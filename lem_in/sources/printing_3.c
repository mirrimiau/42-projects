/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:32:59 by mapostol          #+#    #+#             */
/*   Updated: 2022/08/03 16:33:01 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	calculate_rsa_cont(t_room *start, int ret, int *ants, int *j)
{
	int	i;

	if (!ret && *j < start->i_out)
		(*j)++;
	if (*j >= start->i_out || start->edges_out[*j]->end->d == -1)
	{
		while (*ants)
		{
			i = 0;
			while (i < *j && *ants)
			{
				start->edges_out[i]->end->reserve++;
				(*ants)--;
				i++;
			}
		}
		return (1);
	}
	return (0);
}

void	calculate_route_start_ants(t_room *start, int ret, int ants, int j)
{
	int	i;

	while (ants)
	{
		i = 0;
		while (i < j)
		{
			ret = 0;
			if (j < start->i_out && start->edges_out[i]->end->d
				> -1 && start->edges_out[j]->end->d > -1
				&& start->edges_out[j]->end->d > start->edges_out[i]->end->d
				+ start->edges_out[i]->end->reserve)
			{
				ret = 1;
				start->edges_out[i]->end->reserve++;
				ants--;
				if (!ants)
					return ;
			}
			i++;
		}
		if (calculate_rsa_cont(start, ret, &ants, &j))
			break ;
	}
}

void	hand_tickets(t_parsed_data *data)
{
	t_room	*start;

	start = data->liststart;
	while (!start->start)
		start = start->next;
	calculate_route_start_ants(start, 0, data->ants, 1);
}

void	bubblesort_starting_edges(t_parsed_data *data, int i, int j)
{
	t_room	*start;
	t_edge	*temp;

	start = data->liststart;
	while (!start->start)
		start = start->next;
	while (i < start->i_out - 1)
	{
		j = 0;
		while (j < start->i_out - 1 - i)
		{
			if (start->edges_out[j]->end->d == -1 || (start->edges_out[j] \
			->end->d > start->edges_out[j + 1]->end->d && start->edges_out \
			[j + 1]->end->d > -1))
			{
				temp = start->edges_out[j + 1];
				start->edges_out[j + 1] = start->edges_out[j];
				start->edges_out[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	calculate_route_len(t_room *start, t_parsed_data *data,
	t_room *previous, int ret)
{
	int		i;
	t_room	*room;

	room = start;
	while (!room->terminus)
	{
		i = 0;
		while (i < room->i_out)
		{
			if (room->edges_out[i]->flow_in
				&& room->edges_out[i]->end != previous)
			{
				previous = room;
				room = room->edges_out[i]->end;
				ret++;
				break ;
			}
			i++;
		}
	}
	start->d = ret;
	if (ret < data->longest_route)
		data->longest_route = ret;
}
