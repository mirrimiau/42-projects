/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:12:50 by altikka           #+#    #+#             */
/*   Updated: 2022/12/11 15:24:42 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_hashmap(t_hashmap *hm, size_t size, bool is_optab)
{
	size_t	i;

	if (hash_new(hm, size) < 0)
		panic("Error: Couldn't initialize hashmap.");
	if (is_optab)
	{
		i = 0;
		while (i < OPTAB_SIZE)
		{	
			hash_insert(hm, g_optab[i].name, g_optab[i].op_code);
			i++;
		}
	}
}

void	init_lex(t_token *t, t_labtab *lt)
{
	ft_bzero(t, sizeof(*t));
	t->symbol = la_unknown;
	if (ft_vecnew(&t->content, 1, sizeof(char)) < 0)
		panic("Error: Couldn't initialize token content.");
	ft_bzero(lt, sizeof(*lt));
	init_hashmap(&lt->labels, 100, false);
	if (ft_vecnew(&lt->entries, 1, sizeof(t_labtab)) < 0)
		panic("Error: Couldn't initialize label table entries.");
}

void	init_source(t_src *s)
{
	ft_bzero(s, sizeof(*s));
	if (ft_vecnew(&s->buf, 1, sizeof(char)) < 0)
		panic("Error: Couldn't initialize source buffer.");
	s->row = 0;
	s->col = 0;
	s->index = 0;
	s->next = NULL;
	ft_bzero(&s->name, sizeof(size_t) * 2);
	ft_bzero(&s->comment, sizeof(size_t) * 2);
}

void	init_handler(t_sh *d)
{
	ft_bzero(d, sizeof(*d));
	ft_bzero(&d->header, sizeof(&d->header));
	d->header.magic = COREWAR_EXEC_MAGIC;
	d->header.prog_size = 0;
	if (ft_vecnew(&d->code, 1, sizeof(t_statement)) < 0)
		panic("Error: Couldn't initialize exec code.");
	init_hashmap(&d->ops, 32, true);
	d->byte = 0;
	d->filename = NULL;
	d->op_in_line = false;
	d->eof_is_valid = true;
}
