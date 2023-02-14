/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:49:43 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/10 16:49:44 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(char a[BUF][12])
{
	int	i;

	i = 0;
	while (a[i][0])
		i++;
	return (i - 1);
}

t_link	create_first_link(char a[BUF][12])
{
	t_link	ini;
	int		i;

	i = 1;
	ft_strcpy(ini.content, a[0]);
	ini.placement = 0;
	ini.total = stack_len(a);
	ini.next = NULL;
	ini.previous = NULL;
	ini.block = 0;
	while (i <= ini.total)
	{
		if (ft_atoi(a[i]) < ft_atoi(ini.content))
			ft_strcpy(ini.content, a[i]);
		i++;
	}
	ini.c = ft_atoi(ini.content);
	return (ini);
}

int	next_link(char a[BUF][12], t_link *ini)
{
	t_link	*newlink;
	int		i;
	char	*temp;

	newlink = ini;
	while (newlink->next)
		newlink = newlink->next;
	if (newlink->placement >= newlink->total)
		return (0);
	set_next_link_values(newlink);
	i = 0;
	while (a[i][0])
	{
		if (ft_atoi(a[i]) < newlink->next->c && ft_atoi(a[i]) > newlink->c)
			newlink->next->c = ft_atoi(a[i]);
		i++;
	}
	temp = ft_itoa(newlink->next->c);
	ft_strcpy(newlink->next->content, temp);
	free (temp);
	return (1);
}

void	loop_link_ends(t_link *ini)
{
	t_link	*temp;

	temp = ini;
	while (temp->next)
		temp = temp->next;
	temp->next = ini;
	ini->previous = temp;
}

t_link	*create_sorted_link(char a[BUF][12])
{
	t_link	*ini;
	int		ret;

	ret = 1;
	ini = (t_link *) malloc(sizeof(t_link));
	*ini = create_first_link(a);
	ini->block_total = block_count(ini->total);
	while (ret)
		ret = next_link(a, ini);
	loop_link_ends(ini);
	if (ini->previous->block == ini->previous->previous->block + 1)
		ini->previous->block++;
	return (ini);
}
