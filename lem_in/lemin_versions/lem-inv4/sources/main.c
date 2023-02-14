/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:17:09 by mapostol          #+#    #+#             */
/*   Updated: 2022/06/06 15:17:16 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	run_algorithm(t_parsed_data *data)
{
	t_route	*solution;
	t_route	**solution_routes;

	solution = new_route(NULL);
	solution_routes = (t_route **) malloc (sizeof(t_route *) * BUF);
	if (!solution_routes)
		error_kill("malloc ");
	solution_routes[0] = NULL;
	find_solution(data, solution_routes, solution);
	free(solution);
}

void	confirm_flow(t_room *terminus)
{
	t_room	*room;
	int		i;
	int		temp;

	room = terminus->corr_room;
	temp = -1;
	while (!room->start)
	{
		i = 0;
		while (i < room->i_in)
		{
			if (room->edges_in[i]->flow_out && (!room->edges_in[i]->flow_in || !room->terminus)
				&& (room->out || !room->corr_room->pos || room->edges_in[i]->start->pos))
			{
				room->edges_in[i]->flow_in = 1;
				temp = room->index;
				if (room->in && !room->start && !room->terminus)
					room->corr_room->pos = 1;
				room = room->edges_in[i]->start;
				break ;
			}
			i++;
		}
	}
}

int	find_augmented_path(t_parsed_data *data, t_room *start)
{
	int	i;

	if (start->terminus)
		return (1);
	i = 0;
	while (i < start->i_out)
	{
		if (start->in || (!start->edges_out[i]->flow_out && !start->edges_out[i]->end->reserve
			&& (!start->pos || start->edges_out[i]->corr_edge->flow_in || start->token)))
		{
			if (start->out && start->edges_out[i]->corr_edge->flow_in)
				start->edges_out[i]->end->corr_room->token = 1;

			if (start->out)
			{
				start->reserve = 1;
				start->corr_room->reserve = 1;
			}
			start->edges_out[i]->flow_out = 1;
			if (start->edges_out[i]->end->terminus)
				return (1);
			data->queue_len++;
			data->queue[data->queue_len - 1] = start->edges_out[i]->end;
		}
		i++;	
	}
	if (data->i_queue < data->queue_len)
	{
		data->i_queue++;
		return (find_augmented_path(data, data->queue[data->i_queue - 1]));
	}
	return (0);

}

void	check_if_still_pos(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->i_out)
	{
		if (room->edges_out[i]->flow_in)
			return ;
		i++;
	}
	room->pos = 0;
}


void	format_map(t_room *start)
{
	int		i;
	t_room	*room;

	room = start;
	while (room)
	{
		room->reserve = 0;
		room->corr_room->reserve = 0;
		i = 0;
		while (i < room->i_out)
		{
			if (!room->edges_out[i]->flow_in)
				room->edges_out[i]->flow_out = 0;
			if (!room->in && room->edges_out[i]->flow_in && room->edges_out[i]->corr_edge->flow_in)
			{
				room->edges_out[i]->flow_in = 0;
				room->edges_out[i]->flow_out = 0;
				room->edges_out[i]->corr_edge->flow_in = 0;
				room->edges_out[i]->corr_edge->flow_out = 0;
				check_if_still_pos(room);
			}
			if (room->in)
			{
				room->edges_out[i]->flow_in = 0;
				room->edges_out[i]->flow_out = 0;
			}
			i++;
		}
		if (room != room->corr_room)//
		{
			room = room->corr_room;
					room->reserve = 0;
			room->corr_room->reserve = 0;
			i = 0;
			while (i < room->i_out)
			{
				if (!room->edges_out[i]->flow_in)
					room->edges_out[i]->flow_out = 0;
				if (!room->in && room->edges_out[i]->flow_in && room->edges_out[i]->corr_edge->flow_in)
				{
					room->edges_out[i]->flow_in = 0;
					room->edges_out[i]->flow_out = 0;
					room->edges_out[i]->corr_edge->flow_in = 0;
					room->edges_out[i]->corr_edge->flow_out = 0;
				}
				i++;
			}
			room = room->corr_room; //
		}
		room = room->next;
	}
}


void	run_flow_analytics(t_parsed_data *data)
{
	int		ret;
	t_room	*start;
	t_room	*terminus;

	start = data->liststart;
	while (!start->start)
		start = start->next;
	terminus = data->liststart;
	while (!terminus->terminus)
		terminus = terminus->next;
	while (1)
	{
		data->queue_len = 0;
		data->i_queue = 0;
		start->reserve = 0;
		ret = find_augmented_path(data, start);
		if (ret)
		{
			confirm_flow(terminus);
			format_map(data->liststart);
		}
		else
		{
			format_map(data->liststart);
			break;
		}
	}
}

void	print_routes(t_room *start)
{
	int	i;

	i = 0;
	while (i < start->i_out)
	{
		if (start->in && !start->start && !start->terminus)
			start = start->corr_room;
		if (start->edges_out[i]->flow_out)
		{
			ft_printf("-%s", start->edges_out[i]->end->name);
			print_routes(start->edges_out[i]->end);
			return ;
		}
		i++;
	}
}

int	main(int argv, char **argc)
{
	t_parsed_data	*data;

	data = (t_parsed_data *) malloc(sizeof(t_parsed_data));
	if (!data)
		error_kill("malloc ");
	quiet_mode(data, argv, argc);
	parse_data(data);
	read_additional_arguments(argv, argc, data);
	if (data->visual)
		write_debug_data(data->liststart, data);
	run_flow_analytics(data);
	//print_solution(data);
	t_room	*start = data->liststart;
	int i = 0;
	int ret = 0;
	while (!start->start)
		start = start->next;
	while (i < start->connection_count)
	{
		if (calculate_route_len_ds(start->connections[i]) != INT_MAX)
		{
			ft_printf("%s-%s", start->name, start->connections[i]->name);
			print_routes(start->connections[i]);
			ft_printf("\n");
			ret++;
		}
		i++;
	}
	ft_printf("ret = %i\n", ret);
	return (0);
}
