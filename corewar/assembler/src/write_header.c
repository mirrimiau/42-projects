/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:28:09 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/24 12:54:00 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_comment(t_sh *d, int fd)
{
	size_t		i;

	i = 0;
	while (i < COMMENT_LENGTH + 4)
	{
		if (d->header.comment[i])
			write(fd, &d->header.comment[i], 1);
		else
			write(fd, "\0", 1);
		i++;
	}
}

static void	write_name(t_sh *d, int fd)
{
	size_t		i;

	i = 0;
	while (i < PROG_NAME_LENGTH + 4)
	{
		if (d->header.prog_name[i])
			write(fd, &d->header.prog_name[i], 1);
		else
			write(fd, "\0", 1);
		i++;
	}
}

void	write_header(t_sh *d, const int fd)
{
	u_int32_t	magic;
	u_int32_t	exec_size;

	magic = uint_to_bigendian(d->header.magic);
	write(fd, &magic, 4);
	write_name(d, fd);
	exec_size = uint_to_bigendian(d->byte);
	write(fd, &exec_size, 4);
	write_comment(d, fd);
}
