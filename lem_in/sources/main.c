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

void	add_to_route_queue(t_parsed_data *data, t_route *temp)
{
			data->route_queue[data->queue_len] = temp;
			data->route_queue[data->queue_len + 1] = NULL;
}

void	initialize_ant(t_parsed_data *data, t_ant *ant, t_ant *previous)
{
	if (data->antstart)
		previous->next = ant;
	else
		data->antstart = ant;
	ant->next = NULL;
	ant->complete = 0;
	if (data->visual)
	{
		get_next_line(data->colour_fd, &(ant->colour));
		get_next_line(data->shape_fd, &(ant->shape));
	}
}

void	run_algorithm(t_parsed_data *data)
{
	t_room	*start;

	start = data->liststart;
	while (!start->start)
		start = start->next;
	create_solution_map(data, start, NULL, 0);
	format_map(data);
	free_routes(data);
}

int	create_new_ant(t_parsed_data *data, t_room *room)
{
	t_ant	*ant;
	t_ant	*previous;
	int		i;

	i = 0;
	ant = data->antstart;
	while (ant)
	{
		previous = ant;
		i = ant->index;
		ant = ant->next;
	}
	ant = (t_ant *) malloc(sizeof(t_ant));
	if (!ant)
		error_kill("malloc ");
	ant->index = i + 1;
	ant->room = room;
	initialize_ant(data, ant, previous);
	return (i + 1);
}

int	main(int argc, char **argv)
{
	t_parsed_data	*data;
	t_room			*start;

	data = (t_parsed_data *) malloc(sizeof(t_parsed_data));
	if (!data)
		error_kill("malloc ");
	quiet_mode(data, argc, argv);
	parse_data(data);
	read_additional_arguments(argc, argv, data);
	if (data->visual)
		write_visual_data(data->liststart, data);
	run_algorithm(data);
	refresh_distances(data);
	start = data->liststart;
	while (!start->start)
		start = start->next;
	print_solution(data, start);
	if (data->visual)
	{
		fprintf(data->dotfile, "];\n</script>");
		ft_printf("\nDOT file written.\n");
	}
	exit (0);
}
