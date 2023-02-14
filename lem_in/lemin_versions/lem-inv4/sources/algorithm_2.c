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

void	parse_routes(t_parsed_data *data)
{
	t_room	*start;

	start = data->liststart;
	while (!start->start)
		start = start->next;
	data->routestart = new_route(NULL);
	data->routestart->index = 0;
	data->routestart->next = NULL;
	calculate_path(data->routestart, start, data);
}

void	cp4(t_route *route, t_parsed_data *data, t_route *temp, int i)
{
	t_route	*fresh;
	t_room	*room;

	room = data->temp_room;
	i++;
	while (i < room->connection_count)
	{
		if (!room->connections[i]->start && !room->connections[i]->reserve
			&& room->connections[i]->d + temp->len
			< data->longest_route + data->margin)
		{
			fresh = new_route(route);
			copy_route(temp, fresh);
			calculate_path(fresh, room->connections[i], data);
		}
		i++;
	}
	free(temp);
	room->reserve = 0;
}

void	cp3(t_route *route, t_parsed_data *data, t_room *room)
{
	int		i;
	t_route	*temp;

	i = 0;
	temp = (t_route *) malloc(sizeof(t_route));
	if (!temp)
		error_kill("malloc ");
	copy_route(route, temp);
	while (i < room->connection_count)
	{
		if (!room->connections[i]->start && !room->connections[i]->reserve
			&& room->connections[i]->d + route->len < data->longest_route
			+ data->margin)
		{
			calculate_path(route, room->connections[i], data);
			break ;
		}
		i++;
	}
	data->temp_room = room;
	cp4(route, data, temp, i);
}

void	cp2(t_route *route, t_room *start, t_parsed_data *data)
{
	t_room	*room;

	room = start;
	room->reserve = 1;
	if (!room->start)
		add_state(route, room);
	if (room->d == 1)
	{
		data->complete_routes++;
		route->complete = 1;
		room->reserve = 0;
		return ;
	}
	cp3(route, data, room);
}

void	calculate_path(t_route *route, t_room *start, t_parsed_data *data)
{
	if (data->complete_routes)
		return ;
	if (start->terminus)
	{
		data->complete_routes++;
		route->complete = 1;
		start->reserve = 0;
		return ;
	}
	cp2(route, start, data);
}


int		calculate_route_len_ds(t_room *src)
{
	int		len;
	int		i;
	t_room	*room;
	int		flag;

	room = src;
	len = 0;
	flag = 1;
	while (!room->terminus && flag)
	{
		flag = 0;
		i = 0;
		while (i < room->i_out)
		{
			if (room->in || room->edges_out[i]->flow_out)
			{
				room = room->edges_out[i]->end;
				len++;
				flag = 1;
				break ;
			}
			i++;
		}
	}
	if (!room->terminus)
		len = INT_MAX;
	return (len);
}

int		calculate_route_len_us(t_room *src)
{
	int		len;
	int		i;
	t_room	*room;
	int		flag;

	room = src;
	len = 0;
	flag = 1;
	while (!room->start && flag)
	{
		flag = 0;
		i = 0;
		while (i < room->i_in)
		{
			if (room->edges_in[i]->flow_out)
			{
				room = room->edges_in[i]->start;
				len++;
				flag = 1;
				break ;
			}
			i++;
		}
	}
	if (!room->start)
		len = INT_MAX;
	return (len);
}

void	clear_invalid_path(t_room *room)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < room->i_in)
	{
		if (room->edges_in[i]->flow_out)
			return ;
		i++;
	}
	i = 0;
	while (i < room->i_out)
	{
		if (room->edges_out[i]->flow_out)
		{
			room->edges_out[i]->flow_out = 0;
			clear_invalid_path(room->edges_out[i]->end);
		}
		i++;
	}
}

void	reduce_invalid_node_ds(t_room *room, t_edge *second)
{
	int		i;
	t_edge	*temp;

	i = 0;
	while (i < room->i_out)
	{
		if (room->edges_out[i]->flow_out)
			break ;
		i++;
	}
	if (calculate_route_len_ds(room->edges_out[i]->end) > calculate_route_len_ds(second->end))
	{
		temp = room->edges_out[i];
	}
	else
		temp = second;
	temp->flow_out = 0;
	clear_invalid_path(temp->end);
}

void	reduce_invalid_node_us(t_room *room, t_edge *second)
{
	int	i;

	i = 0;
	while (i < room->i_in)
	{
		if (room->edges_in[i]->flow_out)
			break ;
		i++;
	}
	if (calculate_route_len_us(room->edges_in[i]->start) > calculate_route_len_us(second->start))
		room->edges_in[i]->flow_out = 0;
	else
		second->flow_out = 0;
}

void	reduce_nodes_downstream(t_room *liststart)//maybe run this from bottom up to make it more reliable and quicker
{
	t_room	*room;
	int		i;
	int		c;
	int		d;

	d = 1;
	room = liststart;
	while (d < 100)//test
	{
		while (room && room->d != d)
			room = room->next;
		if (!room)
		{
			d++;
			room = liststart;
			continue ;
		}
		i = 0;
		c = 0;
		while (i < room->i_out && !room->start)
		{
			if (room->edges_out[i]->flow_out && c)
			{
				reduce_invalid_node_ds(room, room->edges_out[i]);
				i = 0;
				c = 0;
				continue ;
			}
			else if (room->edges_out[i]->flow_out)
				c = 1;
			i++;
		}
		room = room->next;
	}
}

void	reduce_nodes_upstream(t_room *liststart)
{
	t_room	*room;
	int		i;
	int		c;
	int		d;

	d = 100;
	room = liststart;
	while (d > 0)//test
	{
		while (room && room->d != d)
			room = room->next;
		if (!room)
		{
			d--;
			room = liststart;
			continue ;
		}
		i = 0;
		c = 0;
		while (i < room->i_in && !room->terminus)
		{
			if (room->edges_in[i]->flow_out && c)
			{
				reduce_invalid_node_us(room, room->edges_in[i]);
				i = 0;
				c = 0;
				continue ;
			}
			else if (room->edges_in[i]->flow_out)
				c = 1;
			i++;
		}
		room = room->next;
	}
}

void	erase_route_us(t_room *start)
{
	t_room	*room;
	int		i;

	room = start;
	while (!room->start)
	{
		i = 0;
		while (i < room->i_in)
		{
			if (room->edges_in[i]->flow_out)
			{
				room->edges_in[i]->flow_out = 0;
				room = room->edges_in[i]->start;
				break ;
			}
			i++;
		}
		if (i == room->i_in)
			break ;
	}
}

int	challenge_routes(t_parsed_data *data, t_room *start)
{
	int	i;

	if (start->terminus)
		return (1);
	start->reserve = 1;
	i = 0;
	while (i < start->i_out)
	{
		if (!start->edges_out[i]->end->reserve && start->edges_out[i]->flow_out)
		{
			data->queue_len++;
			data->queue[data->queue_len - 1] = start->edges_out[i]->end;
		}
		else if (start->edges_out[i]->end->reserve && start->edges_out[i]->flow_out && !start->edges_out[i]->end->terminus)
		{
			start->edges_out[i]->flow_out = 0;
		}
		i++;
	}
	if (data->i_queue < data->queue_len)
	{
		data->i_queue++;
		return (challenge_routes(data, data->queue[data->i_queue - 1]));
	}
	return (0);
}