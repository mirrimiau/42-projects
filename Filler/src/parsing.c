/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:38:00 by mapostol          #+#    #+#             */
/*   Updated: 2022/04/01 14:38:02 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* 
For easy debugging:
#include <fcntl.h> //
data->fd = open("resources/txt", O_RDONLY); //
 */
int	initiate_players(t_data *data)
{
	char	temp;

	data->fd = 0;
	temp = 0;
	ft_bzero(data, sizeof(t_data *));
	while (temp != '1' && temp != '2')
		read(data->fd, &temp, 1);
	if (temp == '1')
		data->xo_me = 'O';
	else
		data->xo_me = 'X';
	if (data->xo_me == 'O')
		data->xo_opp = 'X';
	else
		data->xo_opp = 'O';
	return (data->fd);
}

void	parse_map(t_data *data)
{
	char	temp;
	int		i;
	int		j;

	temp = 'a';
	j = 0;
	while (!char_part_of_board(temp))
		read(data->fd, &temp, 1);
	while (j < data->height)
	{
		i = 0;
		while (temp != '\n')
		{
			while (!char_part_of_board(temp))
				read(data->fd, &temp, 1);
			data->map[j][i] = temp;
			i++;
			read(data->fd, &temp, 1);
		}
		read(data->fd, &temp, 1);
		data->map[j][i] = '\0';
		j++;
	}
}

void	parse_piece_dimensions(t_data *data)
{
	char	piecedata[11];
	int		i;

	ft_bzero(piecedata, 11);
	i = 0;
	while (!ft_isdigit(piecedata[i]))
		read(data->fd, piecedata, 1);
	while (ft_isdigit(piecedata[i]))
	{
		i++;
		read(data->fd, piecedata + i, 1);
	}
	data->p_height = ft_atoi(piecedata);
	i = 0;
	ft_bzero(piecedata, 11);
	while (!ft_isdigit(piecedata[i]))
		read(data->fd, piecedata, 1);
	while (ft_isdigit(piecedata[i]))
	{
		i++;
		read(data->fd, piecedata + i, 1);
	}
	data->p_width = ft_atoi(piecedata);
}

void	parse_piece(t_data *data)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	temp = 'a';
	while (i < data->p_height)
	{
		j = 0;
		while (j < data->p_width)
		{
			read(data->fd, &temp, 1);
			while (temp != '*' && temp != '.')
				read(data->fd, &temp, 1);
			data->piece[i][j] = temp;
			j++;
		}
		i++;
	}
}
