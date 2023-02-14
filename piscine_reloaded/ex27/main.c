/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:50:05 by mapostol          #+#    #+#             */
/*   Updated: 2021/10/30 21:50:19 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		bcount;
	char	buf[10];

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	bcount = 1;
	while (bcount)
	{
		bcount = read(fd, buf, 10);
		write(1, buf, bcount);
	}
	close(fd);
	return (0);
}
