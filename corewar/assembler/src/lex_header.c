/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:45:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/10 17:24:15 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*find_ending_quotation(t_src *s)
{
	char	*ptr;

	ptr = (char *)&s->buf.data[s->index + 1];
	while (*ptr != '"')
	{
		s->col++;
		if (*ptr == '\0')
			return (NULL);
		if (*ptr == '\n')
		{
			s->row++;
			s->col = 0;
		}
		ptr++;
	}
	return (ptr);
}

static void	get_header_info(t_sh *d, t_src *s, t_token *t, char c)
{
	char	*p;
	size_t	ofs;

	if (*(char *)&s->buf.data[s->index] != '"')
		panic_lex(NULL, NULL, s->row, s->col);
	p = find_ending_quotation(s);
	if (p)
	{
		ofs = p - (char *)&s->buf.data[++s->index];
		if (ofs > PROG_NAME_LENGTH
			&& c == 'n')
			panic_lex("name", NULL, PROG_NAME_LENGTH, 0);
		if (ofs > COMMENT_LENGTH
			&& c == 'c')
			panic_lex("comment", NULL, COMMENT_LENGTH, 0);
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
		ft_vecpush(&t->content, "\0");
		if (c == 'n')
			ft_memcpy(d->header.prog_name, t->content.data, ofs);
		else
			ft_memcpy(d->header.comment, t->content.data, ofs);
		source_adjust(s, ofs + 1, true);
	}
	else
		panic_lex("Syntax", NULL, s->row, s->col);
}

void	lex_header(t_sh *d, t_src *s, t_token *t)
{
	if (d->code.len && !is_valid_header(s))
		panic_lex("Syntax", t, s->row, s->col);
	if (!ft_strncmp(&s->buf.data[s->index], ".name", 5))
	{
		t->symbol = la_champname;
		s->name[0]++;
		s->name[1] = s->row;
		source_adjust(s, 5, false);
		source_next(s);
		get_header_info(d, s, t, 'n');
	}
	else if (!ft_strncmp(&s->buf.data[s->index], ".comment", 8))
	{
		t->symbol = la_champcomm;
		s->comment[0]++;
		s->comment[1] = s->row;
		source_adjust(s, 8, false);
		source_next(s);
		get_header_info(d, s, t, 'c');
	}
	else
		panic_lex(NULL, t, s->row, s->col);
}
