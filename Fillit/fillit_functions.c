/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:36:42 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/18 18:36:46 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_valid_spot(char solved[25][25], t_map tetrimino, int index[9])
{
	int	a;
	int	b;
	int	count;

	count = 0;
	a = 0;
	b = 0;
	while (tetrimino.cords[b][a] && count < 4)
	{
		if (tetrimino.cords[b][a] == '.')
		{
			raise_x(&a, &b, 4);
			continue ;
		}
		count++;
		if (solved[index[7] + b][index[6] + a - index[5]] != '.')
			return (0);
		raise_x(&a, &b, 4);
		if (a == 0)
			index[5] = 0;
	}
	return (1);
}

int	ft_out(char *reason)
{
	ft_putendl(reason);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	raise_x(int *x, int *y, int dim)
{
	(*x)++;
	if (*x >= dim)
	{
		(*x) = 0;
		(*y)++;
	}
}

void	print_solution(char solved[25][25])
{
	int	x;
	int	y;

	y = 0;
	while (solved[y][0])
	{
		x = 0;
		while (solved[y][x])
		{
			ft_putchar(solved[y][x]);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int	getdim(t_map tetriminos[26 + 1])
{
	float	i;
	float	nb;

	nb = 0;
	i = 0;
	while (*(tetriminos[(int)nb].shape))
		nb++;
	nb *= 4;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	nb = 0;
	while (nb > i)
		nb++;
	return (i);
}
