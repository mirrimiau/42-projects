/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:39:51 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/15 15:39:52 by mapostol         ###   ########.fr       */
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
	i = 0;
	while (i < BUF)
	{
		route->route[i] = 0;
		i++;
	}
	if (routestart)
		previous->next = route;
	return (route);
}

t_route	*new_route(t_route *routestart)
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
	return (initialize_route(route, routestart, previous, i));
}

void	copy_route(t_route *src, t_route *dest)
{
	int	i;

	i = 0;
	while (i < BUF)
	{
		dest->route[i] = src->route[i];
		i++;
	}
	dest->len = src->len;
}

t_foundpath	*new_foundpath(t_room *room, t_foundpath *next,
	t_foundpath *previous, t_foundpath *initial)
{
	t_foundpath	*fresh;

	fresh = (t_foundpath *) malloc(sizeof(t_foundpath));
	if (!fresh)
		error_kill("malloc ");
	fresh->room = room;
	fresh->next = next;
	fresh->previous = previous;
	fresh->initial = initial;
	if (initial)
		fresh->len = initial->len;
	return (fresh);
}
