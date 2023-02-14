/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:15:52 by mapostol          #+#    #+#             */
/*   Updated: 2022/08/03 16:15:54 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	new_edge_in(t_room *start, t_room *end, t_edge *corr)
{
	t_edge	*fresh;

	fresh = (t_edge *) malloc(sizeof(t_edge));
	if (!fresh)
		error_kill("malloc ");
	fresh->start = start;
	fresh->end = end;
	fresh->flow_in = 0;
	fresh->flow_out = 0;
	end->edges_in[end->i_in] = fresh;
	end->i_in++;
	fresh->corr_edge = corr;
	corr->corr_edge = fresh;
}

t_edge	*new_edge_out(t_room *start, t_room *end)
{
	t_edge	*fresh;

	fresh = (t_edge *) malloc(sizeof(t_edge));
	if (!fresh)
		error_kill("malloc ");
	fresh->start = start;
	fresh->end = end;
	fresh->flow_in = 0;
	fresh->flow_out = 0;
	start->edges_out[start->i_out] = fresh;
	start->i_out++;
	return (fresh);
}

void	copy_edges(t_room *src, t_room *dest)
{
	int	i;

	i = 0;
	while (i < src->i_in)
	{
		if (src->edges_in[i]->start->index == dest->index)
		{
			dest->edges_out[dest->i_out] = src->edges_in[i];
			dest->i_out++;
			dest->edges_in[dest->i_in] = src->edges_in[i]->corr_edge;
			dest->i_in++;
			return ;
		}
		i++;
	}
	error_kill("edges ");
}

int	parse_next_connection(char *line, t_room *room, t_parsed_data *data,
	int flag)
{
	char	**array;
	t_room	*first;
	int		i;

	i = 0;
	flag = 0;
	first = room;
	if (ft_strchr(line, '-') == NULL)
		error_kill("map connection ");
	if (!data->quiet)
		ft_printf("%s\n", line);
	while (line[i])
	{
		if (line[i] == '-' && flag)
			error_kill("connection ");
		else if (line[i] == '-')
			flag = 1;
		i++;
	}
	array = ft_strsplit(line, '-');
	connection_validity(room, first, array);
	ft_nuke(array);
	free (array);
	free (line);
	return (1);
}
