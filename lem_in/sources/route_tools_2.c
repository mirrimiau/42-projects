/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:50:40 by mapostol          #+#    #+#             */
/*   Updated: 2022/09/16 13:50:42 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_room(t_room *room)
{
	if (room)
	{
		free(room->name);
		free(room->x);
		free(room->y);
		free(room);
	}
}

void	extend_routes(t_room *room, t_parsed_data *data)
{
	int	i;

	i = 0;
	while (i < room->connection_count)
	{
		if (room->connections[i]->d == -1
			|| room->connections[i]->d > room->d + 1)
		{
			room->connections[i]->d = room->d + 1;
			extend_routes(room->connections[i], data);
		}
		i++;
	}
	if (room->start)
		data->longest_route = room->d;
}

void	check_all_pos(t_room *start)
{
	t_room	*room;
	int		i;

	room = start;
	while (room)
	{
		if (room->pos)
		{
			i = 0;
			while (i < room->i_in)
			{
				if (room->edges_in[i]->flow_in)
					break ;
				i++;
			}
			if (i == room->i_in)
				room->pos = 0;
		}
		room = room->next;
	}
}
