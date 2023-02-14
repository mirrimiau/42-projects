/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:49 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/15 13:14:50 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_distance(t_parsed_data *data)
{
	t_room	*room;

	room = data->liststart;
	while (room != NULL)
	{
		if (room == NULL)
			return ;
		if (room->terminus)
		{
			room->d = 0;
			break ;
		}
		room = room->next;
	}
	extend_routes(room, data);
	parse_groups(data);
}

t_route	*initialize_route(t_route *route, t_route *routestart,
		t_route *previous, int i)
{
	route->next = NULL;
	route->len = 0;
	route->index = i;
	route->complete = 0;
	if (routestart)
		previous->next = route;
	return (route);
}

t_route	*new_route(t_route *routestart, t_room *current_room,
	t_room *previous_room)
{
	t_route	*route;
	t_route	*previous;
	int		i;

	i = 0;
	route = routestart;
	while (route)
	{
		previous = route;
		i = route->index + 1;
		route = route->next;
	}
	route = (t_route *) malloc (sizeof(t_route));
	if (route == NULL)
		error_kill("malloc ");
	route->previous = previous_room;
	route->current = current_room;
	return (initialize_route(route, routestart, previous, i));
}

void	copy_route(t_route *src, t_route *dest)
{
	int	i;

	i = 0;
	while (i < BUF && src->route[i])
	{
		dest->route[i] = src->route[i];
		i++;
	}
	dest->len = src->len;
}
