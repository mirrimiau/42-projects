/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:10:29 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/14 16:10:30 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_legal_room(t_parsed_data *data, int commentdata,
	t_room *first, char *line)
{
	if (first == NULL)
	{
		first = parse_next_room(line, NULL, commentdata, data);
		if (first == NULL)
			error_kill("map ");
		data->liststart = first;
	}
	else
		parse_next_room(line, first, commentdata, data);
	return (parse_rooms(data, 0, first));
}

int	parse_next_connection_mirror(char *name, t_room *connection, t_room *room)
{
	t_room	*first;

	first = room;
	while (room != NULL)
	{
		if (ft_strequ(room->name, name))
		{
			if (!add_connection(room, connection->name, first))
			{
				free (room);
				error_kill("map connection ");
			}
			return (1);
		}
		room = room->next;
	}
	return (0);
}

void	connection_validity(t_room *room, t_room *first, char **array)
{
	while (1)
	{
		if (first == NULL || !array[1] || array[2]
			|| ft_strequ(array[0], array[1]))
			error_kill("map connection ");
		if (ft_strequ(room->name, array[0]))
		{
			if (!add_connection(room, array[1], first))
				error_kill("map connection ");
			break ;
		}
		room = room->next;
		if (room == NULL)
			error_kill("connection ");
	}
	if (!parse_next_connection_mirror(array[1], room, first))
		error_kill("map connection ");
}

void	parse_bottlenecks(t_parsed_data *data, t_room *room, int i, int j)
{
	while (room)
	{
		if (room->start && room->d == -1)
			error_kill("map connection ");
		if (room->d >= 0)
		{
			i = 0;
			while (data->group[room->d][i] != 0)
				i++;
			data->group[room->d][i] += 1;
		}
		room = room->next;
	}
	j = 0;
	while (data->group[j][0] && j <= data->longest_route)
	{
		i = 0;
		while (data->group[j][i])
		{
			i++;
		}
		if (i < data->min_bottleneck && j > 0 && j <= data->longest_route)
			data->min_bottleneck = i;
		j++;
	}
}

void	parse_groups(t_parsed_data *data)
{
	int		i;
	int		j;
	t_room	*room;

	room = data->liststart;
	j = 0;
	while (j < BUF)
	{
		i = 0;
		while (i < BUF)
		{
			data->group[j][i] = 0;
			i++;
		}
		j++;
	}
	parse_bottlenecks(data, room, 0, 0);
}
