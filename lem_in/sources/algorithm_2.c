/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:48:45 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/15 15:48:47 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	format_map(t_parsed_data *data)
{
	t_room	*room;

	room = data->liststart;
	while (room)
	{
		room->reserve = 0;
		clean_unconfirmed_flow(room);
		room = room->next;
	}
	check_all_pos(data->liststart);
}

void	clean_unconfirmed_flow(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->i_out)
	{
		if (!room->edges_out[i]->flow_in)
			room->edges_out[i]->flow_out = 0;
		if (room->edges_out[i]->flow_in && room->edges_out[i]->flow_out
			&& room->edges_out[i]->corr_edge->flow_in
			&& room->edges_out[i]->corr_edge->flow_out)
		{
			room->edges_out[i]->flow_in = 0;
			room->edges_out[i]->flow_out = 0;
			room->edges_out[i]->corr_edge->flow_in = 0;
			room->edges_out[i]->corr_edge->flow_out = 0;
		}
		i++;
	}
}

t_route	*find_augmenting_path_cont2(t_parsed_data *data)
{
	if (data->i_queue++ > data->queue_len)
		return (NULL);
	return (find_augmenting_path(data));
}

t_route	*find_augmenting_path_cont(t_parsed_data *data, t_room *room,
	t_route *route, int i)
{
	t_route	*temp;

	while (i < room->i_out)
	{
		if (!room->edges_out[i]->flow_out && !room->edges_out[i]->end->reserve
			&& (!route->previous || !room->pos || (room->edges_out[i]->end->pos
					&& room->edges_out[i]->corr_edge->flow_in)
				|| route->previous->pos))
		{
			room->edges_out[i]->flow_out = 1;
			if (room->edges_out[i]->end->terminus)
				return (route);
			if (!(room->pos && room->edges_out[i]->end->pos))
				room->reserve = 1;
			data->queue_len++;
			temp = new_route(data->routestart, room->edges_out[i]->end, room);
			add_to_route_queue(data, temp);
			copy_route(route, temp);
			temp->route[temp->len] = room->edges_out[i]->end;
			temp->len++;
		}
		i++;
	}
	return (find_augmenting_path_cont2(data));
}

t_route	*find_augmenting_path(t_parsed_data *data)
{
	t_route	*route;
	t_room	*room;

	route = data->routestart;
	if (data->queue_len > 0)
		route = data->route_queue[data->i_queue];
	if (route == NULL)
		return (NULL);
	room = route->current;
	return (find_augmenting_path_cont(data, room, route, 0));
}
