/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:17:29 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 13:29:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assemble(t_sh *d, char *filename)
{
	int	fd;

	d->filename = create_filename(filename);
	fd = open(d->filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		panic("Error: Couldn't create output file.");
	write_file(d, fd);
	free_data(d);
	close(fd);
}
