/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:37:28 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/22 16:01:41 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	read_and_write(char temp[1000], char *ptr)
{
	int	x;

	x = 0;
	while (x != 20)
	{
		ft_strncat(temp, &ptr[x], 4);
		x += 4 + 1;
		if (ptr[x - 1] != '\n')
			return (0);
	}
	return (1);
}

int	read_create_tetriminos(t_map tetriminos[26 + 1], int fd)
{
	char	buf[1000];

	ft_bzero(buf, 1000);
	if (read(fd, buf, 1000) < 1)
		return (0);
	return (create_tetriminos(tetriminos, buf));
}

int	create_tetriminos(t_map tetriminos[26 + 1], char buf[1000])
{
	char	temp[1000];
	char	*ptr;
	int		i;

	i = 0;
	while (i != 27)
	{
		ptr = &buf[i * 21];
		if (!*ptr)
			break ;
		ft_bzero(temp, 1000);
		if (read_and_write(temp, ptr) == 0)
			return (0);
		if (!(check_validity(temp, tetriminos[i].shape)))
			return (0);
		i++;
	}
	if (*(ptr - 1) != '\0')
		return (0);
	*(tetriminos[i].shape) = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	tetriminos[26 + 1];
	char	solved[25][25];
	int		fd;
	int		dim;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		return (ft_out("usage: ./fillit [input file]"));
	if (!(read_create_tetriminos(tetriminos, fd)))
		return (ft_out("error"));
	set_coordinates(tetriminos);
	dim = getdim(tetriminos);
	solve_tetriminos(tetriminos, solved, dim);
	if (!solved[0][0])
		return (ft_out("error"));
	print_solution(solved);
	return (0);
}
