/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:54:25 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 13:54:35 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_labels(t_labtab *lt)
{
	t_label	*temp;
	size_t	i;

	i = 0;
	while (i < lt->entries.len)
	{
		temp = ft_vecget(&lt->entries, i);
		if (!temp)
			continue ;
		if (temp->declared == false)
		{
			ft_dprintf(2, "No such label %s while attempting to dereference "
				"token [%zu:%zu] LABEL AS ARGUMENT \"%s\"\n", temp->name,
				temp->pos[0] + 1, temp->pos[1] + 1, temp->name);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
