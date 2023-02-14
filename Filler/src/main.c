/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:32:26 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/21 12:32:28 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initiate_data(t_data *data)
{
	char	temp[11];
	int		i;

	i = 0;
	ft_bzero(temp, 11);
	initiate_players(data);
	while (!ft_isdigit(temp[i]))
		read(data->fd, temp, 1);
	while (ft_isdigit(temp[i]))
	{
		i++;
		read(data->fd, temp + i, 1);
	}
	data->height = ft_atoi(temp);
	i = 0;
	ft_bzero(temp, 11);
	while (!ft_isdigit(temp[i]))
		read(data->fd, temp, 1);
	while (ft_isdigit(temp[i]))
	{
		i++;
		read(data->fd, temp + i, 1);
	}
	data->width = ft_atoi(temp);
	data->initialize = 1;
}

int	take_turn(t_data *data)
{
	while (1)
	{
		parse_map(data);
		create_heatmap(data);
		parse_piece_dimensions(data);
		parse_piece(data);
		if (place_piece(data) == 0)
			return (1);
		else
			return (0);
		return (1);
	}
}

int	main(void)
{
	t_data	data;
	int		ret;

	if (data.initialize != 0 && data.initialize != 1)
		data.initialize = 0;
	if (!data.initialize)
		initiate_data(&data);
	while (1)
	{
		ret = take_turn(&data);
		if (ret != 0)
			ft_printf("%d %d\n", data.y, data.x);
		else
		{
			ft_putstr("0 0\n");
			return (0);
		}
	}
}
