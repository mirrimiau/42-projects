/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:15:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/08 12:32:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex(t_sh *d, t_flag *f, t_src *s)
{
	t_token		t;
	t_labtab	lt;
	size_t		tnum;

	init_lex(&t, &lt);
	tnum = 1;
	while (t.symbol != la_eof)
	{
		source_next(s);
		lex_tokenization(d, s, &t, &lt);
		if (*f == DEBUG)
			debug_lex(&t, s, tnum++);
		if (t.symbol == la_eof)
			continue ;
		if (t.symbol == la_unknown)
			panic_lex(NULL, &t, s->row, s->col);
		reset_token(&t);
	}
	check_labels(&lt);
	if (*f == DEBUG)
		debug_statement(d);
	free_labtab(&lt);
	ft_vecdel(&t.content);
}
