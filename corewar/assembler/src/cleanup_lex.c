/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_lex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:03:16 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/30 17:53:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	labtab_lst_free(t_undeflab *head)
{
	t_undeflab	*temp;

	temp = head->next;
	free(head);
	while (temp)
	{
		head = temp;
		temp = head->next;
		free(head);
	}
}

static void	free_hm_keys(t_hashmap *src)
{
	size_t	i;

	i = 0;
	while (i < src->capacity)
	{
		if (src->entries[i].key)
			ft_strdel(&src->entries[i].key);
		i++;
	}
	hash_free(src);
}

void	free_labtab(t_labtab *lt)
{
	t_label	*lab;
	size_t	i;

	i = 0;
	while (i < lt->entries.len)
	{
		lab = ft_vecget(&lt->entries, i);
		if (lab->head != NULL)
			labtab_lst_free(lab->head);
		i++;
	}
	free_hm_keys(&lt->labels);
	ft_vecdel(&lt->entries);
}
