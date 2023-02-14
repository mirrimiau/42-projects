/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_comma.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:45:36 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/05 16:46:16 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_separators(t_statement *stmt, int row, int col)
{
	if (stmt->sep != stmt->cur_arg || stmt->sep == stmt->op.argc)
		panic_lex(NULL, NULL, row, col);
}

void	lex_comma(t_sh *d, t_src *s, t_token *t)
{
	t_statement	*stmt;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	if (!stmt || stmt->op.argc == 1)
		panic_lex(NULL, NULL, s->row, s->col);
	stmt->sep++;
	validate_separators(stmt, s->row, s->col);
	t->symbol = la_comma;
	ft_vecncat(&t->content, ",", 1);
	ft_vecpush(&t->content, "\0");
	source_adjust(s, 1, false);
}
