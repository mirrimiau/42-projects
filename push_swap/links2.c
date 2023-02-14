/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:02:15 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/16 13:02:17 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
This function exists for debugging purposes.
*/
void	printlinks(t_link *ini)
{
	t_link	*temp;
	int		i;

	i = 0;
	temp = ini;
	while (i <= temp->total)
	{
		ft_printf("%s\n", temp->content);
		temp = temp->next;
		i++;
	}
}

void	set_next_link_values(t_link *newlink)
{
	newlink->next = (t_link *) malloc(sizeof(t_link));
	newlink->next->total = newlink->total;
	newlink->next->placement = newlink->placement + 1;
	newlink->next->next = NULL;
	newlink->next->previous = newlink;
	newlink->next->block_total = newlink->block_total;
	newlink->next->block = newlink->next->placement
		/ ((newlink->total + newlink->block_total - 1) / newlink->block_total);
	newlink->next->c = INT_MAX;
}

t_link	*get_link(char *content, t_link *sorted)
{
	while (1)
	{
		if (ft_strequ(sorted->content, content))
			return (sorted);
		sorted = sorted->next;
	}
}

void	free_links(t_link *sorted)
{
	t_link	*temp;
	t_link	*next;
	int		total;

	total = sorted->total;
	temp = sorted;
	while (total >= 0)
	{
		next = temp->next;
		temp->block = 0;
		temp->block_total = 0;
		temp->c = 0;
		temp->placement = 0;
		temp->total = 0;
		temp->previous = NULL;
		temp->next = NULL;
		free(temp);
		temp = next;
		total--;
	}
}
