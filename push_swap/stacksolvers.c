/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksolvers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:21:54 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/10 16:21:55 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_twostack(char a[BUF][12])
{
	if (ft_atoi(a[0]) > ft_atoi(a[1]))
		ft_printf("sa\n");
}

void	threestack_case_2_1(char a[BUF][12])
{
	if (ft_atoi(a[1]) > ft_atoi(a[2]))
	{
		ft_printf("sa\nrra\n");
		swap(a);
		reverse_rotate(a);
	}
	else if (ft_atoi(a[0]) > ft_atoi(a[2]))
	{
		ft_printf("ra\n");
		rotate(a);
	}
	else
	{
		ft_printf("sa\n");
		swap(a);
	}
}

void	solve_threestack(char a[BUF][12])
{
	if (ft_atoi(a[0]) > ft_atoi(a[1]))
		threestack_case_2_1(a);
	else
	{
		if (ft_atoi(a[1]) > ft_atoi(a[2]) && ft_atoi(a[2]) > ft_atoi(a[0]))
		{
			ft_printf("sa\nra\n");
			swap(a);
			rotate(a);
		}
		else if (ft_atoi(a[0]) > ft_atoi(a[2]))
		{
			ft_printf("rra\n");
			reverse_rotate(a);
		}
	}
}

void	solve_fivestack(char a[BUF][12], char b[BUF][12])
{
	t_link	*sorted;

	sorted = create_sorted_link(a);
	put(b, a);
	ft_printf("pb\n");
	if (a[3][0])
	{
		put(b, a);
		ft_printf("pb\n");
	}
	solve_threestack(a);
	while (b[0][0])
		smartput_from_b_to_a(a, b, sorted);
	smart_orientate_a(a, sorted->content, stack_len(a));
	free_links(sorted);
}

void	solve_largestack(char a[BUF][12], char b[BUF][12])
{
	t_link	*sorted;
	int		block;
	char	initial[12];
	int		i;

	sorted = create_sorted_link(a);
	block = sorted->block_total;
	ft_strcpy(initial, sorted->content);
	while (block >= 0)
	{
		put_block(b, a, block, sorted);
		sorted = get_link(a[0], sorted);
		i = 0;
		while (sorted->block != block + 1 && block + 1 < sorted->block_total)
		{
			sorted = get_link(a[i], sorted);
			i++;
		}
		smart_orientate_a(a, sorted->content, stack_len(a));
		block--;
		sorted_block_b_to_a(a, b);
	}
	smart_orientate_a(a, initial, sorted->total);
	free_links(sorted);
}
