/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:52:48 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/14 15:52:49 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	handle_illegal_rooms(char **array)
{
	int	i;

	i = 0;
	while (array[1][i])
	{
		if (!ft_isdigit(array[1][i]))
			error_kill("room ");
		i++;
	}
	i = 0;
	while (array[2][i])
	{
		if (!ft_isdigit(array[2][i]))
			error_kill("room ");
		i++;
	}
}

int	is_room_legal(char *line, t_room *first)
{
	char	**array;

	array = ft_strsplit(line, ' ');
	if (!array[0] || !array[1] || !array[2] || array[3])
	{
		ft_nuke(array);
		free(array);
		return (0);
	}
	while (first)
	{
		if (ft_strequ(first->name, array[0]) || (ft_strequ(first->x, array[1])
				&& ft_strequ(first->y, array[2])))
		{
			ft_nuke(array);
			free(array);
			return (0);
		}
		first = first->next;
	}
	handle_illegal_rooms(array);
	ft_nuke(array);
	free(array);
	return (1);
}

int	add_connection(t_room *room, char *connection, t_room *first)
{
	t_room	**fresh;

	while (first != NULL)
	{
		if (ft_strequ(first->name, connection))
		{
			if (room->connections == NULL)
			{
				room->connections = (t_room **) malloc(sizeof(t_room *) * 2);
				room->connections[0] = first;
				room->connections[1] = NULL;
			}
			else
			{
				fresh = (t_room **) malloc(sizeof(t_room *) * BUF);
				copy_room_array_and_add(room->connections, fresh, first);
				free(room->connections);
				room->connections = fresh;
			}
			room->connection_count++;
			return (1);
		}
		first = first->next;
	}
	return (0);
}

t_room	*allocate_room_and_print(char *line, int commentdata, char **array,
	t_parsed_data *data)
{
	t_room	*new;

	new = (t_room *) malloc(sizeof(t_room));
	if (new == NULL)
		error_kill("malloc ");
	new->name = ft_strdup(array[0]);
	new->x = ft_strdup(array[1]);
	new->y = ft_strdup(array[2]);
	new->connection_count = 0;
	new->start = 0;
	new->terminus = 0;
	new->d = -1;
	new->connections = NULL;
	if (commentdata == 1)
		new->start = 1;
	if (commentdata == 2)
		new->terminus = 1;
	new->next = NULL;
	if (!data->quiet)
		ft_printf("%s\n", line);
	return (new);
}

t_room	*parse_next_room(char *line, t_room *first, int commentdata,
	t_parsed_data *data)
{
	char	**array;
	t_room	*new;

	array = NULL;
	array = ft_strsplit(line, ' ');
	if (!array[0] || !array[1] || !array[2] || array[3])
		ft_nuke(array);
	else
		new = allocate_room_and_print(line, commentdata, array, data);
	ft_nuke(array);
	free (array);
	if (first != NULL)
	{
		while (first->next)
			first = first->next;
		first->next = new;
	}
	free(line);
	return (new);
}
