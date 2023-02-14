/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:24:18 by mapostol          #+#    #+#             */
/*   Updated: 2022/08/03 16:24:19 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	refresh_distances(t_parsed_data *data)
{
	t_room	*start;
	int		i;

	start = data->liststart;
	data->longest_route = INT_MAX;
	while (!start->start)
		start = start->next;
	i = 0;
	while (i < start->i_out)
	{
		if (start->edges_out[i]->end->pos)
			calculate_route_len(start->edges_out[i]->end, data,
				NULL, 0);
		else
			start->edges_out[i]->end->d = -1;
		i++;
	}
	bubblesort_starting_edges(data, 0, 0);
	hand_tickets(data);
}

void	write_movement_to_dot(t_ant *ant, t_parsed_data *data)
{
	fprintf(data->dotfile, "\t'%s [shape=%s,\
		color=%s,style=filled];',\n",
		ant->room->name, ant->shape, ant->colour);
}

void	move_ant(t_ant *ant, t_parsed_data *data)
{
	int	i;

	i = 0;
	while (i < ant->room->i_out)
	{
		if (ant->room->edges_out[i]->flow_in)
		{
			if (!data->rowstart && !data->quiet)
				write(1, " ", 1);
			else
				data->rowstart = 0;
			if (!data->quiet)
				ft_printf("L%i-%s", ant->index,
					ant->room->edges_out[i]->end->name);
			ant->room = ant->room->edges_out[i]->end;
			if (ant->room->terminus)
				ant->complete = 1;
			break ;
		}
		i++;
	}
	if (data->visual)
		write_movement_to_dot(ant, data);
}

int	round_of_ants(t_parsed_data *data)
{
	int		ret;
	t_ant	*ant;

	if (data->antstart == NULL)
		return (1);
	ret = 0;
	ant = data->antstart;
	while (ant)
	{
		if (!ant->complete)
		{
			move_ant(ant, data);
			ret = 1;
		}
		ant = ant->next;
	}
	return (ret);
}

void	write_movement_index_i(int i, t_parsed_data *data)
{
	t_ant	*ant;

	ant = data->antstart;
	while (i != ant->index)
		ant = ant->next;
	write_movement_to_dot(ant, data);
}
