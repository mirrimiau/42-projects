/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:55:19 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/01 11:42:02 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_file(t_sh *d, const int fd)
{
	write_header(d, fd);
	write_bytecode(d, fd);
	ft_printf("Writing output program to %s\n", d->filename);
}
