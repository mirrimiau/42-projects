/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_endof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:21:04 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/12 11:25:46 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	validate_eof(t_statement *stmt)
{
	if (!stmt)
		panic("Error: Invalid champion.");
}

static void	validate_eol(t_src *s, t_statement *stmt)
{
	if (stmt->sep != stmt->op.argc - 1 || stmt->cur_arg != stmt->op.argc)
		panic_invalidarg(NULL, s, stmt);
	stmt->is_valid = true;
}

void	lex_endof(t_sh *d, t_src *s, t_token *t)
{
	t_statement	*stmt;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	if (*(char *)&s->buf.data[s->index] == '\n')
	{
		if (stmt && stmt->is_valid == false)
			validate_eol(s, stmt);
		t->symbol = la_eol;
		ft_vecpush(&t->content, "\n");
		ft_vecpush(&t->content, "\0");
		s->row++;
		s->col = 0;
		s->index++;
		d->eof_is_valid = true;
	}
	else if (*(char *)&s->buf.data[s->index] == '\0')
	{
		validate_eof(stmt);
		if ((stmt && stmt->is_valid == false) || d->eof_is_valid == false)
			panic_lex("Unexpected end", NULL, s->row, s->col);
		t->symbol = la_eof;
		ft_vecpush(&t->content, "\0");
	}
	d->op_in_line = false;
}
