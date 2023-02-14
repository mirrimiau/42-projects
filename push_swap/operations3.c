/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:17:34 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/16 15:17:36 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	block_x_in_stack(char a[BUF][12], int block, t_link *sorted)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (a[i][0])
	{
		sorted = get_link(a[i], sorted);
		if (sorted->block == block)
			ret++;
		i++;
	}
	return (ret);
}

void	orientate_last_member(char a[BUF][12], int block, t_link *sorted)
{
	int	i;

	i = 0;
	sorted = get_link(a[0], sorted);
	while (sorted->block != block)
	{
		i++;
		sorted = get_link(a[i], sorted);
	}
	smart_orientate_a(a, a[i], sorted->total);
}

void	calculate_top_and_bottom(t_block_minmax *info, char src[BUF][12],
			int block, t_link *sorted)
{
	info->top = 0;
	info->bottom = stack_len(src);
	while (info->top < info->bottom)
	{
		info->temp = get_link(src[info->top], sorted);
		if (info->temp->block == block)
			break ;
		info->top++;
	}
	while (info->bottom > 0)
	{
		info->temp = get_link(src[info->bottom], sorted);
		if (info->temp->block == block)
			break ;
		info->bottom--;
	}
	info->bottom = stack_len(src) - info->bottom + 1;
}

void	smartorientate_block_member_to_top(t_block_minmax info,
			char src[BUF][12])
{
	if (info.top <= info.bottom)
	{
		while (info.top > 0)
		{
			ft_printf("ra\n");
			rotate(src);
			info.top--;
		}
	}
	else
	{
		while (info.bottom > 0)
		{
			ft_printf("rra\n");
			reverse_rotate(src);
			info.bottom--;
		}
	}
}

void	put_block(char dest[BUF][12], char src[BUF][12],
			int block, t_link *sorted)
{
	t_block_minmax	info;

	while (0 < block_x_in_stack(src, block, sorted))
	{
		calculate_top_and_bottom(&info, src, block, sorted);
		smartorientate_block_member_to_top(info, src);
		ft_printf("pb\n");
		put(dest, src);
	}
}
