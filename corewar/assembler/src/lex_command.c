/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:29:33 by altikka           #+#    #+#             */
/*   Updated: 2022/12/11 15:25:27 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	create_statement(t_sh *d, t_src *s, t_token *t, char *key)
{
	t_statement	temp;
	t_hash		*entry;

	if (d->op_in_line)
		panic_lex("Syntax", t, s->row, s->col);
	d->op_in_line = true;
	entry = hash_get(&d->ops, key);
	temp.op = g_optab[entry->value - 1];
	temp.acb = 0;
	temp.loc = d->byte;
	d->byte += 1 + g_optab[temp.op.op_code - 1].acb;
	temp.cur_arg = 0;
	temp.sep = 0;
	temp.is_dir = false;
	temp.is_valid = false;
	ft_bzero(temp.arg_type, sizeof(u_int8_t) * 3);
	if (ft_vecpush(&d->code, &temp) < 0)
		panic("Error: Malloc error with exec code.");
}

static void	lex_operation(t_sh *d, t_src *s, t_token *t)
{
	char	*p;
	size_t	ofs;

	t->symbol = la_op;
	p = (char *)&s->buf.data[s->index];
	while (is_label_chars(*p))
		p++;
	ofs = p - (char *)&s->buf.data[s->index];
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	ft_vecpush(&t->content, "\0");
	if (s->name[0] != 1 || s->comment[0] != 1
		|| s->name[1] == s->comment[1])
		panic_lex("Syntax", t, s->row, s->col);
	if (!hash_lookup(&d->ops, (char *)t->content.data))
		panic_lex("Syntax", t, s->row, s->col);
	create_statement(d, s, t, (char *)t->content.data);
	source_adjust(s, ofs, false);
}

static void	command_label(t_sh *d, t_labtab *lt, char *key)
{
	t_hash	*entry;

	entry = hash_get(&lt->labels, key);
	if (!entry)
		hash_insert(&lt->labels, key, d->byte);
	else if (entry)
	{
		label_fill(d, &lt->entries, entry, false);
		ft_strdel(&key);
	}
}

void	lex_command(t_sh *d, t_src *s, t_token *t, t_labtab *lt)
{
	char	*p;
	size_t	ofs;

	d->eof_is_valid = false;
	if (is_label(s))
	{
		t->symbol = la_label;
		p = ft_strchr(&s->buf.data[s->index], LABEL_CHAR);
		ofs = p - (char *)&s->buf.data[s->index] + 1;
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs - 1);
		ft_vecpush(&t->content, "\0");
		if (!is_valid_header(s))
			panic_lex("Syntax", t, s->row, s->col);
		command_label(d, lt,
			ft_strndup((char *)t->content.data, t->content.len));
		source_adjust(s, ofs, false);
	}
	else
		lex_operation(d, s, t);
}
