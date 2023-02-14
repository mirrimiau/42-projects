/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:43:19 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/18 20:43:22 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_null_to_top(t_map tetrimino, int i[3])
{
	tetrimino.cords[i[1]][i[2]] = 0;
	i[2] = 0;
	i[1]++;
}

void	set_coordinates(t_map tetriminos[26 + 1])
{
	int		i[3];
	char	*ptr;

	ft_bzero(i, sizeof(i));
	while (*(tetriminos[i[0]].shape))
	{
		ptr = tetriminos[i[0]].shape;
		while (*ptr)
		{
			tetriminos[i[0]].c = 'A' + i[0];
			if (*ptr == '.')
				tetriminos[i[0]].cords[i[1]][i[2]] = '.';
			if (*ptr == '#')
				tetriminos[i[0]].cords[i[1]][i[2]] = tetriminos[i[0]].c;
			i[2]++;
			if (i[2] == 4)
				add_null_to_top(tetriminos[i[0]], i);
			if (i[1] == 3)
				tetriminos[i[0]].cords[i[1] + 1][i[2]] = 0;
			ptr++;
		}
		i[0]++;
		i[1] = 0;
	}
}

void	empty_map(char solved[25][25], int dim)
{
	int	y;
	int	x;

	y = 0;
	while (y < dim)
	{
		x = 0;
		while (x < dim)
		{
			solved[y][x] = '.';
			x++;
		}
		solved[y][x] = '\0';
		y++;
	}
	x = 0;
	solved[y][x] = '\0';
}

void	backtrack_to_map(char solved[25][25], int dim, int *x, int *y)
{
	if (!solved[*y][*x])
	{
		while (!solved[*y][*x])
		{
			(*x)--;
			if (*x < 0)
			{
				*x = dim - 1;
				(*y)--;
			}
		}
	}
}
