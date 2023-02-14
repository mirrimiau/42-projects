/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:41:39 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/14 15:41:41 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_validity(t_parsed_data *data)
{
	t_room	*room;
	int		start;
	int		terminus;

	start = 0;
	terminus = 0;
	room = data->liststart;
	while (room)
	{
		if (room->terminus)
			terminus++;
		if (room->start)
			start++;
		room = room->next;
	}
	if (terminus != 1 || start != 1)
		error_kill("map ");
}

int	is_line_comment(char *line)
{
	if (!line)
		error_kill("file ");
	if (line[0] == '#')
	{
		ft_printf("%s\n", line);
		if (ft_strequ(line, "##start"))
			return (1);
		if (ft_strequ(line, "##end"))
			return (2);
		return (3);
	}
	return (0);
}

void	copy_room_array_and_add(t_room **src, t_room **dest, t_room *new)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (ft_strequ(src[i]->name, new->name))
			error_kill("connection duplicate ");
		dest[i] = src[i];
		i++;
	}
	dest[i] = new;
	dest[i + 1] = NULL;
}

void	parse_indices(t_parsed_data *data)
{
	t_room	*room;
	int		i;

	room = data->liststart;
	i = 0;
	while (room)
	{
		room->index = i;
		room->reserve = 0;
		i++;
		room = room->next;
	}
	data->rooms = i;
	data->min_bottleneck = INT_MAX;
}

int	parse_ants(t_parsed_data *data)
{
	int		i;
	char	*line;
	int		ret;

	i = 0;
	ret = get_next_line(0, &line);
	if (ret < 1 || !line)
		error_kill("file ");
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			error_kill("ants ");
		i++;
	}
	data->ants = ft_atoi(line);
	ft_printf("%s\n", line);
	free (line);
	return (1);
}
