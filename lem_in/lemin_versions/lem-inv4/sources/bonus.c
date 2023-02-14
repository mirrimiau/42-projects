/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:33:50 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/15 14:33:53 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_dot(t_room *room, FILE *fp)
{
	int	j;

	if (room->terminus != 0)
	{
		ft_printf("\t this is the terminus\n");
		fprintf(fp, "\t%s %s;\n", room->name, "[shape=polygon,sides=5,\
			peripheries=3,color=lightblue,style=filled]");
	}
	if (room->start != 0)
	{
		ft_printf("\t this is the starting room\n");
		fprintf(fp, "\t%s %s;\n", room->name, "[shape=polygon,sides=3,\
			peripheries=2,color=pink,style=filled]");
	}
	ft_printf("Room connection count: %i\n", room->connection_count);
	ft_printf("Room connects to: ");
	j = 0;
	while (j < room->connection_count)
	{
		ft_printf("%s ", room->connections[j]->name);
		fprintf(fp, "\t%s -- %s;\n", room->name, room->connections[j]->name);
		j++;
	}
}

void	write_debug_data(t_room *room, t_parsed_data *data)
{
	int		i;
	int		j;
	FILE	*fp;

	i = 1;
	j = 0;
	system("touch visualizer/graph.dot");
	fp = fopen("visualizer/graph.dot", "w+");
	fprintf(fp, "strict graph g {\n");
	ft_printf("\nDEBUG\nThere are %i ants\n", data->ants);
	while (room != NULL)
	{
		ft_printf("Room %i:\n", i);
		ft_printf("Name: %s\n", room->name);
		ft_printf("Coordinates: %s, %s\n", room->x, room->y);
		ft_printf("Distance from terminus: %i\n", room->d);
		write_dot(room, fp);
		ft_printf("\n\n");
		i++;
		room = room->next;
	}
	fprintf(fp, "}\n");
	ft_printf("DOT file written.\n");
}

void	quiet_mode(t_parsed_data *data, int argv, char **argc)
{
	if (argv > 1)
	{
		if (ft_strequ(argc[1], "-q"))
			data->quiet = 1;
		else
			data->quiet = 0;
	}
	else
		data->quiet = 0;
}

void	read_additional_arguments(int argv, char **argc, t_parsed_data *data)
{
	if (argv > 1)
	{
		if (ft_strequ(argc[1], "-v"))
			data->verbose = 1;
		else if (ft_strequ(argc[1], "-m"))
			data->visual = 1;
		else if (ft_strequ(argc[1], "-q"))
			data->quiet = 1;
		if (argv > 2 && ft_atoi(argc[2]) > 0)
			data->margin_cap = ft_atoi(argc[2]);
		if (argv > 3 && ft_atoi(argc[3]) > 0)
			data->bypass = ft_atoi(argc[3]);
	}
}
