/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:40:46 by mapostol          #+#    #+#             */
/*   Updated: 2022/04/01 14:40:47 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	calculate_heat(t_data *f)
{
	int	i;
	int	j;
	int	heat;

	heat = 0;
	j = 0;
	while (j < f->p_height)
	{
		i = 0;
		while (i < f->p_width)
		{
			if (f->piece[j][i] == '*')
				heat += f->heatmap[j + f->y][i + f->x];
			i++;
		}
		j++;
	}
	return (heat);
}

int	heatmap_complete(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (data->heatmap[j][i] == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	format_heatmap(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	ft_bzero(data->heatmap, BUF * BUF);
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (ft_toupper(data->map[j][i]) == data->xo_opp)
				data->heatmap[j][i] = 1;
			i++;
		}
		j++;
	}
}

void	compare_orthogonal_heat(t_data *data, int *i, int *j, int min)
{
	if (*j - 1 > 0 && data->heatmap[*j - 1][*i] != 0)
	{
		min = data->heatmap[*j - 1][*i] + 1;
	}
	if (*j + 1 < data->height && data->heatmap[*j + 1][*i] != 0)
	{
		if (data->heatmap[*j + 1][*i] + 1 < min)
			min = data->heatmap[*j + 1][*i] + 1;
	}
	if (*i - 1 > 0 && data->heatmap[*j][*i - 1] != 0)
	{
		if (data->heatmap[*j][*i - 1] + 1 < min)
			min = data->heatmap[*j][*i - 1] + 1;
	}
	if (*i + 1 < data->width
		&& data->heatmap[*j][*i + 1] != 0)
	{
		if (data->heatmap[*j][*i + 1] + 1 < min)
			min = data->heatmap[*j][*i + 1] + 1;
	}
	if (min == INT_MAX)
		min = 0;
	data->heatmap[*j][*i] = min;
}

void	create_heatmap(t_data *data)
{
	int	i;
	int	j;

	format_heatmap(data);
	while (1)
	{
		j = 0;
		while (j < data->height)
		{
			i = 0;
			while (i < data->width)
				calculate_heat_row(data, &i, &j);
			j++;
		}
		if (heatmap_complete(data))
			return ;
	}
}
