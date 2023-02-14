/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:40:29 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/14 15:40:31 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mark_flow_to_terminus(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->i_out)
	{
		if (room->edges_out[i]->end->terminus)
		{
			room->edges_out[i]->flow_in = 1;
			return ;
		}
		i++;
	}
}

void	convert_route_to_flow(t_route *route, t_room *start)
{
	int		i;
	int		j;
	t_room	*room;

	j = 0;
	room = start;
	while (j < route->len)
	{
		i = 0;
		while (i < room->i_out)
		{
			if (room->edges_out[i]->end == route->route[j])
			{
				room->edges_out[i]->flow_in = 1;
				break ;
			}
			i++;
		}
		room = room->edges_out[i]->end;
		room->pos = 1;
		j++;
	}
	mark_flow_to_terminus(room);
}

int	calculate_expected_result(t_parsed_data *data, t_room *start)
{
	int		ret;
	int		i;
	t_room	*room;

	room = data->liststart;
	while (room)
	{
		room->reserve = 0;
		room = room->next;
	}
	refresh_distances(data);
	i = 0;
	ret = 0;
	while (i < start->i_out)
	{
		if (start->edges_out[i]->end->reserve < 1)
			break ;
		if (ret < start->edges_out[i]->end->reserve
			+ start->edges_out[i]->end->d)
			ret = start->edges_out[i]->end->reserve
				+ start->edges_out[i]->end->d;
		i++;
	}
	return (ret);
}

void	init_solution_map(t_parsed_data *data, t_room *start)
{
		data->i_queue = 0;
		data->queue_len = 0;
		data->routestart = new_route(data->routestart, start, NULL);
}

void	create_solution_map(t_parsed_data *data, t_room *start,
			t_route *route, int exp)
{
	while (1)
	{
		init_solution_map(data, start);
		route = find_augmenting_path(data);
		if (route)
		{
			route->complete = 1;
			exp = calculate_expected_result(data, start);
			if (!data->buffer && exp >= data->exp_res)
				break ;
			else if (!data->buffer)
				data->exp_res = exp;
			else
				data->buffer--;
			convert_route_to_flow(route, start);
			format_map(data);
			free_routes(data);
			free (route);
		}
		else
		{
			free (route);
			break ;
		}
	}
}
