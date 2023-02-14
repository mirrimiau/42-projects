/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:38:29 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/14 11:38:31 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	block_count(int total)
{
	int	i;

	i = 1;
	while (total > i * i)
		i++;
	i--;
	i = (i + 1) / 2;
	if (i == 0)
		return (1);
	return (i);
}

void	print_member_in_block_col(t_link *sorted)
{
	if (sorted->block == 0)
		ft_printf("%{W}-14s", sorted->content);
	if (sorted->block == 1)
		ft_printf("%{Y}-14s", sorted->content);
	if (sorted->block == 2)
		ft_printf("%{R}-14s", sorted->content);
	if (sorted->block == 3)
		ft_printf("%{G}-14s", sorted->content);
	if (sorted->block == 4)
		ft_printf("%{C}-14s", sorted->content);
	if (sorted->block == 5)
		ft_printf("%{B}-14s", sorted->content);
	if (sorted->block == 6)
		ft_printf("%{M}-14s", sorted->content);
}

void	print_db_data(char a[BUF][12], char b[BUF][12], t_link *sorted)
{
	int	i;

	i = 0;
	ft_printf("%{O}s", "\n");
	ft_printf("\n%{ak}s", " ");
	ft_printf("%-14s%-14s\n\n", "Stack A:", "Stack B:");
	while (a[i][0] || b[i][0])
	{
		if (a[i][0])
		{
			sorted = get_link(a[i], sorted);
			print_member_in_block_col(sorted);
		}
		else
			ft_printf("%-14s", "-");
		if (b[i][0])
		{
			sorted = get_link(b[i], sorted);
			print_member_in_block_col(sorted);
			ft_printf("\n");
		}
		else
			ft_printf("%-14s\n", "-");
		i++;
	}
}
