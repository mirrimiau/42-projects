/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:56:06 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/11 12:56:07 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_block_min_and_max(t_block_minmax *info, char b[BUF][12])
{
	int	i;

	info->largest_i = 0;
	info->smallest_i = 0;
	ft_strcpy(info->largest, b[0]);
	ft_strcpy(info->smallest, b[0]);
	i = 0;
	while (b[i][0])
	{
		if (ft_atoi(info->largest) < ft_atoi(b[i]))
		{
			ft_strcpy(info->largest, b[i]);
			info->largest_i = i;
		}
		if (ft_atoi(info->smallest) > ft_atoi(b[i]))
		{
			ft_strcpy(info->smallest, b[i]);
			info->smallest_i = i;
		}
		i++;
	}
}

int	case_largest_is_closest(t_block_minmax info, char b[BUF][12])
{
	if (((info.largest_i < info.smallest_i && info.largest_i
				< (stack_len(b) - info.smallest_i + 1)) || ((stack_len(b)
					- info.largest_i + 1) < info.smallest_i && (stack_len(b)
					- info.largest_i + 1) < (stack_len(b)
					- info.smallest_i + 1))) && info.largest_i
		!= info.smallest_i)
		return (1);
	return (0);
}

void	sorted_block_b_to_a(char a[BUF][12], char b[BUF][12])
{
	t_block_minmax	info;

	while (b[0][0])
	{
		find_block_min_and_max(&info, b);
		if (case_largest_is_closest(info, b))
		{
			smart_orientate_b(b, info.largest, stack_len(b));
			put(a, b);
			ft_printf("pa\n");
		}
		else if (info.largest_i != info.smallest_i)
		{
			smart_orientate_b(b, info.smallest, stack_len(b));
			put(a, b);
			rotate(a);
			ft_printf("pa\nra\n");
		}
		else
		{
			put(a, b);
			ft_printf("pa\n");
		}
	}
}

void	smartput_find_next(char a[BUF][12], char b[BUF][12], t_link *sorted)
{
	int	i;

	while (1)
	{
		while (ft_strcmp(sorted->content, b[0]))
			sorted = sorted->next;
		i = 0;
		if (check_if_in_stack(a, sorted->next->content))
		{
			smart_orientate_a(a, sorted->next->content, stack_len(a));
			ft_printf("pa\n");
			put(a, b);
			break ;
		}
		ft_printf("rb\n");
		rotate(b);
	}
}

void	smartput_from_b_to_a(char a[BUF][12], char b[BUF][12], t_link *sorted)
{
	while (ft_strcmp(sorted->content, a[0]))
		sorted = sorted->next;
	if (sorted->previous && ft_strequ(b[0], sorted->previous->content))
	{
		ft_printf("pa\n");
		put(a, b);
	}
	else if (sorted->next && ft_strequ(b[0], sorted->next->content))
	{
		ft_printf("ra\npa\n");
		rotate(a);
		put(a, b);
	}
	else
		smartput_find_next(a, b, sorted);
}
