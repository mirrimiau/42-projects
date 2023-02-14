/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:17:09 by mapostol          #+#    #+#             */
/*   Updated: 2022/06/06 15:17:16 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_next_connection(char *line, t_room *room, t_parsed_data *data,
	int flag)
{
	char	**array;
	t_room	*first;
	int		i;

	i = 0;
	flag = 0;
	first = room;
	if (ft_strchr(line, '-') == NULL)
		error_kill("map connection ");
	if (!data->quiet)
		ft_printf("%s\n", line);
	while (line[i])
	{
		if (line[i] == '-' && flag)
			error_kill("connection ");
		else if (line[i] == '-')
			flag = 1;
		i++;
	}
	array = ft_strsplit(line, '-');
	connection_validity(room, first, array);
	ft_nuke(array);
	free (array);
	free (line);
	return (1);
}

/* 
	if comment, write, collect data and start over
	if room and first == null, initialize first
	if room after that, push to list
	if none of above
		if connector, collect and exit function
		if not, kill
*/
int	parse_rooms(t_parsed_data *data, int commentdata, t_room *first)
{
	int		ret;
	char	*line;

	if (!memsafe_gnl(&line))
		return (0);
	ret = is_line_comment(line);
	if (ret > 0)
	{
		if (commentdata == 1 || commentdata == 2)
			error_kill("comment ");
		free (line);
		return (parse_rooms(data, ret, first));
	}
	else if (is_room_legal(line, first))
		return (parse_legal_room(data, commentdata, first, line));
	return (parse_next_connection(line, first, data, 0));
}

int	parse_connections(t_room *first, t_parsed_data *data)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = memsafe_gnl(&line);
		if (ret > 0)
		{
			if (is_line_comment(line) > 0 && line[0])
				free(line);
			else
				ret = parse_next_connection(line, first, data, 0);
		}
	}
	return (1);
}

void	new_edge_in(t_room *start, t_room *end, t_edge *corr)
{
	t_edge	*fresh;

	fresh = (t_edge *) malloc(sizeof(t_edge));
	if (!fresh)
		error_kill("malloc ");
	fresh->start = start;
	fresh->end = end;
	fresh->flow_in = 0;
	fresh->flow_out = 0;
	end->edges_in[end->i_in] = fresh;
	end->i_in++;
	fresh->corr_edge = corr;
	corr->corr_edge = fresh;
}

t_edge	*new_edge_out(t_room *start, t_room *end)
{
	t_edge	*fresh;

	fresh = (t_edge *) malloc(sizeof(t_edge));
	if (!fresh)
		error_kill("malloc ");
	fresh->start = start;
	fresh->end = end;
	fresh->flow_in = 0;
	fresh->flow_out = 0;
	start->edges_out[start->i_out] = fresh;
	start->i_out++;
	return (fresh);
}

void	copy_edges(t_room *src, t_room *dest)
{
	int	i;

	i = 0;
	while (i < src->i_in)
	{
		if (src->edges_in[i]->start->index == dest->index)
		{
			dest->corr_room->edges_out[dest->corr_room->i_out] = src->edges_in[i];
			dest->corr_room->i_out++;
			dest->edges_in[dest->i_in] = src->edges_in[i]->corr_edge;
			dest->i_in++;
			return ;
		}
		i++;
	}
	error_kill("edges ");
}

void	create_internal_edge(t_room	*room)
{
	t_edge	*edge;

	edge = (t_edge *) malloc(sizeof(t_edge));
	if (!edge)
		error_kill("malloc");
	edge->start = room;
	edge->end = room->corr_room;
	edge->flow_in = 0;
	edge->flow_out = 0;
	edge->corr_edge = NULL;//or point to itself?
	room->edges_out[room->i_out] = edge;
	room->i_out++;
	room->corr_room->edges_in[room->corr_room->i_in] = edge;
	room->corr_room->i_in++;
}

void	parse_edges(t_room *start)
{
	t_room	*room;
	t_edge	*temp;
	int		i;

	room = start;
	while (room)
	{
		if (!room->start && !room->terminus)
			create_internal_edge(room);
		i = 0;
		while (i < room->connection_count)
		{
			if (room->connections[i]->index > room->index)
			{
				temp = new_edge_out(room->corr_room, room->connections[i]);
				new_edge_in(room->connections[i]->corr_room, room, temp);
			}
			else
				copy_edges(room->connections[i], room);
			i++;
		}
		room = room->next;
	}
}

void	duplicate_to_exit(t_room *src)
{
	t_room	*fresh;

	if (src->start || src->terminus)
		fresh = src;
	else
		fresh = (t_room *) malloc(sizeof(t_room));
	if (!fresh)
		error_kill("malloc ");
	fresh->name = src->name;
	fresh->index = src->index;
	fresh->start = src->start;
	fresh->terminus = src->terminus;
	fresh->connections = src->connections;
	fresh->connection_count = src->connection_count;
	fresh->reserve = 0;
	fresh->x = src->x;
	fresh->y = src->y;
	fresh->corr_room = src;
	src->corr_room = fresh;
	fresh->in = 0;
	fresh->out = 1;
	fresh->i_in = 0;
	fresh->i_out = 0;
	fresh->pos = 0;
	src->pos = 0;
	fresh->token = 0;
}

void	split_rooms(t_room *liststart)
{
	t_room	*room;

	room = liststart;
	while (room)
	{
		room->in = 1;
		room->out = 0;
		duplicate_to_exit(room);
		room = room->next;
	}
}


int	parse_data(t_parsed_data *data)
{
	int		ret;

	ret = parse_ants(data);
	data->longest_route = 0;
	if (ret)
		ret = parse_rooms(data, 0, 0);
	if (ret)
		ret = parse_connections(data->liststart, data);
	else
		error_kill("connection ");
	clean_connectionless_rooms(data->liststart);
	check_validity(data);
	parse_indices(data);
	parse_distance(data);
	data->routestart = NULL;
	data->margin_cap = 15;
	data->complete_routes = 0;
	data->max_turns = data->longest_route + data->ants - 1;
	data->margin = MARGIN;
	data->verbose = 0;
	data->visual = 0;
	data->queue_len = 0;
	data->i_queue = 0;
	split_rooms(data->liststart);
	parse_edges(data->liststart);
	/* t_room	*room = data->liststart;
	int i;
	while (room)
	{
		ft_printf("Room: %s, in: %i, out: %i\nConnections in:\n", room->name, room->in, room->out);
		i = 0;
		while (i < room->i_in)
		{
			ft_printf("%s\n", room->edges_in[i]->start->name);
			i++;
		}
		ft_printf("out:\n");
		i = 0;
		while (i < room->i_out)
		{
			ft_printf("%s\n", room->edges_out[i]->end->name);
			i++;
		}
		ft_printf("\n");
		if (room->corr_room != room)
		{
			room = room->corr_room;
			ft_printf("Room: %s, in: %i, out: %i\nConnections in:\n", room->name, room->in, room->out);
			i = 0;
			while (i < room->i_in)
			{
				ft_printf("%s\n", room->edges_in[i]->start->name);
				i++;
			}
			ft_printf("out:\n");
			i = 0;
			while (i < room->i_out)
			{
				ft_printf("%s\n", room->edges_out[i]->end->name);
				i++;
			}
			ft_printf("\n");
			room = room->corr_room;
		}
		room = room->next;
	}
	exit(0); */
	return (1);
}
