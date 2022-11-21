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

void	combine_routes(t_route *src, t_route *dest)
{
	int	i;

	i = 0;
	while (i < BUF)
	{
		dest->route[i] = dest->route[i] | src->route[i];
		i++;
	}
}

void	refresh_map(t_parsed_data *data, t_route *solution)
{
	t_room	*room;

	room = data->liststart;
	while (room)
	{
		if (compare_route_to_index(solution, room->index))
			room->reserve = 1;
		room = room->next;
	}
	data->complete_routes = 0;
	parse_routes(data);
	room = data->liststart;
	while (room)
	{
		room->reserve = 0;
		room = room->next;
	}
}

void	free_unused_routes(t_parsed_data *data)
{
	t_route	*temp;

	while (data->routestart)
	{
		temp = data->routestart;
		data->routestart = data->routestart->next;
		if (!temp->complete)
			free (temp);
	}
}

int	find_augmenting_path(t_parsed_data *data, t_route *solution,
	t_route **solution_routes, int i)
{
	t_route	*temp;

	temp = data->routestart;
	while (temp)
	{
		if (temp->complete && !data->bypass)
		{
			combine_routes(temp, solution);
			if (data->verbose)
				ft_printf("margin %i found\n", data->margin);
			solution_routes[i] = temp;
			solution_routes[i + 1] = NULL;
			i++;
			break ;
		}
		else if (temp->complete)
			data->bypass--;
		temp = temp->next;
	}
	if (temp == NULL)
		data->margin++;
	free_unused_routes(data);
	return (i);
}

void	find_solution(t_parsed_data *data, t_route **solution_routes,
	t_route *solution)
{
	int	i;

	i = 0;
	while (data->margin < data->margin_cap)
	{
		refresh_map(data, solution);
		i = find_augmenting_path(data, solution, solution_routes, i);
		if (!solution_routes[0] && data->margin > 1)
			error_kill("bypass ");
		data->solution_routes = solution_routes;
		data->solution_i = i;
	}
}
