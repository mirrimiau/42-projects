/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:20:20 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/15 13:20:21 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	change_initial(t_foundpath *initial)
{
	t_foundpath	*temp;
	t_foundpath	*new;

	new = initial;
	while (new && new->next && new->next->next)
		new = new->next;
	temp = initial;
	while (temp)
	{
		temp->initial = new;
		temp->room->reserve = 0;
		temp = temp->next;
	}
}


void	run_printing_logic(t_parsed_data *data, t_foundpath *list[BUF],
	int flag, int i)
{
	t_foundpath	*temp;

	while (1)
	{
		flag = 0;
		i = 0;
		while (list[i])
		{
			temp = list[i]->initial;
			while (temp != NULL)
			{
				if (temp->room->reserve > 0 || (temp->room->start
						&& data->ants > 0
						&& (temp->len - data->longest_route) <= data->ants))
					flag = force_movement(data, temp->room, temp->next->room);
				temp = temp->previous;
			}
			i++;
		}
		if (!flag)
			break ;
		if (!data->quiet)
			ft_printf("\n");
		data->linecount++;
	}
}

t_foundpath	*path_to_linked_list(t_route *route, t_room *start,	t_room *terminus)
{
 	t_foundpath	*initial;
	t_foundpath	*temp;
	t_room		*room;
	t_room		*previous;

	initial = new_foundpath(start, NULL, NULL, NULL);
	initial->len = route->len;
	initial->initial = initial;
	temp = initial;
	previous = NULL;
	while (1)
	{
		temp->next = NULL;
		room = find_corresponding_room(route, temp->room, previous);
		if (room == NULL)
		{
			temp->next = new_foundpath(terminus, NULL, temp, initial);
			break ;
		}
		temp->next = new_foundpath(room, NULL, temp, initial);
		temp = temp->next;
		previous = temp->previous->room;
	}
	change_initial(initial);
	return (initial);
}

t_room	*next_room_from(t_room *start)
{
	int	i;

	i = 0;
	while (i < start->i_out)
	{
		if (start->edges_out[i]->flow_out)
			return (start->edges_out[i]->end);
		i++;
	}
	return (NULL);
}

t_foundpath	*write_route(t_room *start,	t_room *second, t_room *terminus)
{
	t_foundpath	*initial;
	t_foundpath	*temp;
	t_room		*room;
	t_room		*previous;

	initial = new_foundpath(start, NULL, NULL, NULL);
	initial->len = calculate_route_len_ds(second);
	initial->initial = initial;
	temp = initial;
	previous = start;
	room = second;
	while (1)
	{
		temp->next = NULL;
		if (temp->room != start)
			room = next_room_from(temp->room);
		if (room->terminus)
		{
			temp->next = new_foundpath(terminus, NULL, temp, initial);
			break ;
		}
		temp->next = new_foundpath(room, NULL, temp, initial);
		temp = temp->next;
		previous = temp->previous->room;
	}
	change_initial(initial);
	return (initial);
}

void	print_solution(t_parsed_data *data)
{
	t_foundpath	*list[BUF];
	int			i;
	int			j;
	t_room		*start;
	t_room		*terminus;

	ft_printf("\n");
	i = 0;
	j = 0;
	start = data->liststart;
	terminus = data->liststart;
	while (!start->start)
		start = start->next;
	while (!terminus->terminus)
		terminus = terminus->next;
	while (j < start->i_out)
	{
		if (calculate_route_len_ds(start->edges_out[j]->end) != INT_MAX)
		{
			list[i] = write_route(start, start->edges_out[j]->end, terminus);
			i++;
		}
		j++;
	}
	list[i] = NULL;
	data->linecount = 0;
	run_printing_logic(data, list, 0, 0);
	if (data->verbose || data->quiet)
		ft_printf("linecount: %i\n", data->linecount);
	exit (0);
}
