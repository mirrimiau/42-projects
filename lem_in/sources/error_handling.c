/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:31:44 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/14 15:31:47 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_kill(char *reason)
{
	if (reason)
		write(2, reason, ft_strlen(reason));
	write(2, "error\n", 6);
	exit(0);
}

//free char** regardless of innards.
void	ft_nuke(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
}

int	memsafe_gnl(char **line)
{
	int	ret;

	*line = NULL;
	ret = get_next_line(0, line);
	if (*line == NULL && ret == -1)
		error_kill("file ");
	if (ret < 1)
	{
		return (0);
	}
	return (1);
}

void	clean_connectionless_rooms(t_room *first)
{
	t_room	*room;
	t_room	*temp;

	while (!first->connections)
	{
		room = first->next;
		first = room;
	}
	temp = first;
	if (temp->next)
		room = temp->next;
	while (room)
	{
		if (!room->connections)
		{
			temp->next = room->next;
			free_room(room);
			room = temp->next;
		}
		else
		{
			temp = temp->next;
			room = room->next;
		}
	}
}

void	free_routes(t_parsed_data *data)
{
	t_route	*temp;

	while (data->routestart)
	{
		temp = data->routestart;
		data->routestart = data->routestart->next;
		if (!temp->complete)
		{
			free (temp);
			temp = NULL;
		}
	}
	data->routestart = NULL;
}
