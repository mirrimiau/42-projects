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
		fprintf(fp, "\t'%s %s;',\n", room->name, "[shape=polygon\
			,sides=5, peripheries=3,color=lightblue,style=filled]");
	if (room->start != 0)
		fprintf(fp, "\t'%s %s;',\n", room->name, "[shape=polygon\
			,sides=3, peripheries=2,color=pink,style=filled]");
	j = 0;
	while (j < room->connection_count)
	{
		fprintf(fp, "'\t%s -- %s;',\n", room->name, room->connections[j]->name);
		j++;
	}
}

void	write_visual_data(t_room *room, t_parsed_data *data)
{
	FILE	*fp;
	int		colour_fd;
	int		shape_fd;

	system("touch visualizer/graph.html");
	system("cat visualizer/js_base.txt > visualizer/graph.html");
	fp = fopen("visualizer/graph.html", "a");
	colour_fd = open("visualizer/colours.txt", O_RDONLY);
	shape_fd = open("visualizer/shapes.txt", O_RDONLY);
	fprintf(fp, "\n[\n'strict graph g {',\n");
	while (room != NULL)
	{
		write_dot(room, fp);
		room = room->next;
	}
	fprintf(fp, "'}'\n],\n");
	data->dotfile = fp;
	data->colour_fd = colour_fd;
	data->shape_fd = shape_fd;
}

void	quiet_mode(t_parsed_data *data, int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strequ(argv[1], "-q"))
			data->quiet = 1;
		else
			data->quiet = 0;
	}
	else
		data->quiet = 0;
}

void	read_additional_arguments(int argc, char **argv, t_parsed_data *data)
{
	if (argc > 1)
	{
		if (ft_strequ(argv[1], "-v"))
			data->verbose = 1;
		else if (ft_strequ(argv[1], "-m"))
			data->visual = 1;
		else if (ft_strequ(argv[1], "-q"))
			data->quiet = 1;
		else if (ft_strequ(argv[1], "-r"))
			data->r = 1;
	}
}
