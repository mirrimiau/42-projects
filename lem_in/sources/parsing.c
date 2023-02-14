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

void	parse_edges(t_room *start)
{
	t_room	*room;
	t_edge	*temp;
	int		i;

	room = start;
	while (room)
	{
		i = 0;
		while (i < room->connection_count)
		{
			if (room->connections[i]->index > room->index)
			{
				temp = new_edge_out(room, room->connections[i]);
				new_edge_in(room->connections[i], room, temp);
			}
			else
				copy_edges(room->connections[i], room);
			i++;
		}
		room = room->next;
	}
}

int	init_data(t_parsed_data *data)
{
	data->routestart = NULL;
	data->complete_routes = 0;
	data->max_turns = data->longest_route + data->ants - 1;
	data->verbose = 0;
	data->visual = 0;
	data->antstart = NULL;
	data->exp_res = INT_MAX;
	data->buffer = 3;
	data->r = 0;
	data->rowstart = 1;
	return (1);
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
	init_data(data);
	parse_edges(data->liststart);
	return (1);
}
