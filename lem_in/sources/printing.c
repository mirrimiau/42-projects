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

void	print_next_route(t_room *room)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < room->i_out)
		{
			if (room->edges_out[i]->flow_in)
			{
				room = room->edges_out[i]->end;
				ft_printf("-%s", room->name);
				break ;
			}
			i++;
		}
		if (room->terminus)
			break ;
	}
}

void	print_out_routes(t_room *start)
{
	int		j;
	t_room	*room;

	j = 0;
	ft_printf("Routes used:\n");
	while (j < start->i_out)
	{
		if (start->edges_out[j]->end->reserve > 0)
		{	
			room = start->edges_out[j]->end;
			ft_printf("%s-%s", start->name, room->name);
			print_next_route(room);
			ft_printf("\n\n");
		}
		j++;
		if (j >= start->i_out || start->edges_out[j]->end->reserve < 1)
			break ;
	}
	ft_printf("Total routes used: %i", j);
}

void	send_out_new_ants(t_parsed_data *data, t_room *start, int ant)
{
	int	i;

	i = 0;
	while (i < start->i_out)
	{
		if (start->edges_out[i]->end->d > -1)
		{	
			if (start->edges_out[i]->end->reserve)
			{
				ant = create_new_ant(data, start->edges_out[i]->end);
				if (!data->quiet && !data->rowstart)
					write (1, " ", 1);
				else
					data->rowstart = 0;
				if (!data->quiet)
					ft_printf("L%i-%s", ant,
						start->edges_out[i]->end->name);
				if (data->visual)
					write_movement_index_i(ant, data);
				start->edges_out[i]->end->reserve--;
			}
		}
		i++;
	}
}

int	print_out_standard_solution(t_parsed_data *data,
	t_room *start, int linecount)
{
	t_room	*room;

	while (1)
	{
		if (data->visual)
			fprintf(data->dotfile, "\n[\n'strict graph g {',\n");
		if (!data->quiet)
			ft_printf("\n");
		data->rowstart = 1;
		if (!round_of_ants(data))
			break ;
		linecount++;
		send_out_new_ants(data, start, 0);
		if (data->visual)
		{
			room = data->liststart;
			while (room)
			{
				write_dot(room, data->dotfile);
				room = room->next;
			}
			fprintf(data->dotfile, "'}'\n],\n");
		}
	}
	return (linecount);
}

void	print_solution(t_parsed_data *data, t_room *start)
{
	int		linecount;

	if (!data->r)
		linecount = print_out_standard_solution(data, start, 0);
	if (data->visual)
		fprintf(data->dotfile, "'byeeee}'\n],\n");
	if ((data->verbose || data->quiet) && !data->r)
		ft_printf("\nlinecount: %i\n", linecount);
	if (data->r)
		print_out_routes(start);
}
