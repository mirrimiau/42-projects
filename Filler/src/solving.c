/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:43:10 by mapostol          #+#    #+#             */
/*   Updated: 2022/04/01 14:43:11 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	calculate_heat_row(t_data *data, int *i, int *j)
{
	int	min;

	min = INT_MAX;
	if (data->heatmap[*j][*i] == 0)
		compare_orthogonal_heat(data, i, j, min);
	(*i)++;
}

int	char_part_of_board(char c)
{
	if (c == '.' || c == '#' || c == 'x'
		|| c == 'X' || c == 'o' || c == 'O')
		return (1);
	return (0);
}

int	check_collisions(t_data *f)
{
	int		i;
	int		j;
	int		single_collision;
	char	cell;

	single_collision = 0;
	i = 0;
	while (i < f->p_height)
	{
		j = 0;
		while (j < f->p_width && single_collision <= 1)
		{
			cell = ft_toupper(f->map[f->y + i][f->x + j]);
			if (f->piece[i][j] == '*' && cell == f->xo_me)
				single_collision++;
			else if (f->piece[i][j] == '*' && cell == f->xo_opp)
				return (-1);
			j++;
		}
		i++;
	}
	if (single_collision == 1)
		return (0);
	return (-1);
}

void	resolve_row(t_data *f, int *heat, int *x_opt, int *y_opt)
{
	f->x = 0;
	while (f->x + f->p_width <= f->width)
	{
		if (check_collisions(f) == 0)
		{
			if (calculate_heat(f) < *heat)
			{
				*x_opt = f->x;
				*y_opt = f->y;
				*heat = calculate_heat(f);
			}
		}
		f->x++;
	}
}

int	place_piece(t_data *f)
{
	int	heat;
	int	x_opt;
	int	y_opt;

	heat = INT_MAX;
	f->y = 0;
	while (f->y + f->p_height <= f->height)
	{
		resolve_row(f, &heat, &x_opt, &y_opt);
		f->y++;
	}
	if (heat == INT_MAX)
		return (-1);
	f->x = x_opt;
	f->y = y_opt;
	return (0);
}
