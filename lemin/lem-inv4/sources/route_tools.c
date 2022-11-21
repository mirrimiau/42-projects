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

int	force_movement(t_parsed_data *data, t_room *src, t_room *dest)
{
	if (dest->reserve || (src->start && data->ants < 1))
		return (1);
	if (!data->quiet)
		ft_printf("L%s-%s ", src->name, dest->name);
	if (!dest->terminus)
		dest->reserve++;
	if (src->start)
		data->ants--;
	else
		src->reserve--;
	return (1);
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

void	add_state(t_route *route, t_room *room)
{
	int					i;
	int					g;
	unsigned long long	identity;

	identity = 1;
	i = room->index % 64;
	g = room->index / 64;
	route->route[g] += identity << i;
	route->len++;
}

int	compare_route_to_index(t_route *route, int index)
{
	int					g;
	int					i;
	unsigned long long	identity;

	identity = 1;
	g = index / 64;
	i = index % 64;
	if (route->route[g] & (identity << i))
		return (1);
	return (0);
}

t_room	*find_corresponding_room(t_route *route, t_room *start,
	t_room *previous)
{
	int	i;

	i = 0;
	while (i < start->connection_count)
	{
		if (compare_route_to_index(route, start->connections[i]->index)
			&& start->connections[i] != previous
			&& !start->connections[i]->reserve)
		{
			start->connections[i]->reserve = 1;
			return (start->connections[i]);
		}
		i++;
	}
	return (NULL);
}
