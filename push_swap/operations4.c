/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:48:11 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/16 15:48:12 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_in_stack(char a[BUF][12], char *needle)
{
	int	i;

	i = 0;
	while (a[i][0])
	{
		if (ft_strequ(needle, a[i]))
			return (1);
		i++;
	}
	return (0);
}

void	rotate_multiple(int r, char stack, char a[BUF][12])
{
	while (r > 0)
	{
		ft_printf("r%c\n", stack);
		rotate(a);
		r--;
	}
}

void	smart_orientate_b(char a[BUF][12], char *first, int total)
{
	int	r;
	int	rr;

	r = 0;
	rr = 0;
	while (ft_strcmp(a[r], first))
		r++;
	while (ft_strcmp(a[total - rr], first))
		rr++;
	if (r <= rr)
		rotate_multiple(r, 'b', a);
	else
	{
		while (rr >= 0)
		{
			ft_printf("rrb\n");
			reverse_rotate(a);
			rr--;
		}
	}
}

void	smart_orientate_a(char a[BUF][12], char *first, int total)
{
	int	r;
	int	rr;

	r = 0;
	rr = 0;
	while (ft_strcmp(a[r], first))
		r++;
	while (ft_strcmp(a[total - rr], first))
		rr++;
	if (r <= rr)
		rotate_multiple(r, 'a', a);
	else
	{
		while (rr >= 0)
		{
			ft_printf("rra\n");
			reverse_rotate(a);
			rr--;
		}
	}
}
