/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/05 12:24:42 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex_comment(t_src *s, t_token *t)
{
	char	*p;

	p = ft_strchr(&s->buf.data[s->index], '\n');
	if (!p)
	{
		ft_vecncat(&t->content, &s->buf.data[s->index],
			s->buf.len - s->index - 1);
		ft_vecpush(&t->content, "\0");
		source_adjust(s, s->buf.len - s->index, false);
	}
	else
	{
		ft_vecncat(&t->content, &s->buf.data[s->index],
			p - (char *)&s->buf.data[s->index]);
		ft_vecpush(&t->content, "\0");
		source_adjust(s, p - (char *)&s->buf.data[s->index], false);
	}
	t->symbol = la_comm;
}
