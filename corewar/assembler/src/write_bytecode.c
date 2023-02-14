/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:06:21 by altikka           #+#    #+#             */
/*   Updated: 2022/12/05 17:04:53 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_args(t_statement *stmt, const int fd)
{
	u_int32_t	ind;
	u_int16_t	dir;
	size_t		i;

	i = 0;
	while (i < (size_t)stmt->op.argc)
	{
		if (stmt->op.size == 4 && stmt->arg_type[i] == DIR_CODE)
		{
			ind = uint_to_bigendian(stmt->args[i]);
			write(fd, &ind, 4);
		}
		else if (stmt->arg_type[i] == DIR_CODE || stmt->arg_type[i] == IND_CODE)
		{
			dir = ushort_to_bigendian(stmt->args[i]);
			write(fd, &dir, 2);
		}
		else
			write(fd, &stmt->args[i], 1);
		i++;
	}
}

static void	write_acb(t_statement *stmt, const int fd)
{
	stmt->acb = stmt->arg_type[0] << 6 | stmt->acb;
	stmt->acb = stmt->arg_type[1] << 4 | stmt->acb;
	stmt->acb = stmt->arg_type[2] << 2 | stmt->acb;
	write(fd, &stmt->acb, 1);
}

void	write_bytecode(t_sh *d, const int fd)
{
	t_statement	*stmt;
	size_t		i;

	i = 0;
	while (i < d->code.len)
	{
		stmt = ft_vecget(&d->code, i);
		write(fd, &stmt->op.op_code, 1);
		if (stmt->op.acb == true)
			write_acb(stmt, fd);
		write_args(stmt, fd);
		i++;
	}
}
