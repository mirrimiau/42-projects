/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:28:22 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:28:34 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

#define RIGHTMOST_TWO_BITS 0x03

unsigned char	get_crumb(unsigned char c_byte, int c_number)
{
	unsigned char	crumb;

	crumb = (c_byte >> (CRUMBS_IN_BYTE - c_number) * 2) & RIGHTMOST_TWO_BITS;
	return (crumb);
}

unsigned int	cast_arg_type_to_bytes(unsigned char arg_type, unsigned char op)
{
	if (arg_type == DIR_CODE)
		return (g_op[op][OP_DIR]);
	else if (arg_type == IND_CODE)
		return (IND_SIZE);
	else if (arg_type == REG_CODE)
		return (1);
	return (0);
}

static unsigned int	get_argument_wo_cbyte(t_info *info, t_car *car)
{
	if (car->op == 0x01)
		return ((info->memory[(car->pc + 1) % MEM_SIZE] << 24)
			+ (info->memory[(car->pc + 2) % MEM_SIZE] << 16)
			+ (info->memory[(car->pc + 3) % MEM_SIZE] << 8)
			+ (info->memory[(car->pc + 4) % MEM_SIZE]));
	return ((info->memory[(car->pc + 1) % MEM_SIZE] << 8)
		+ (info->memory[(car->pc + 2) % MEM_SIZE]));
}

unsigned int	cat_n_bytes(unsigned char *offset,
	unsigned int bytes, unsigned char memory[])
{
	unsigned int	i;
	unsigned int	sum;
	unsigned char	*c;

	i = 0;
	sum = 0;
	c = offset;
	while (i < bytes)
	{
		sum = sum << 8;
		sum += *c;
		if (c == &memory[MEM_SIZE - 1])
			c = &memory[0];
		else
			c++;
		i++;
	}
	return (sum);
}

/* Finds argument n (where 1 <= n <= 3, 4 is for theoretical statements)
	for the carriages current op */
unsigned int	get_argument(t_info *info, unsigned char n, t_car *car)
{
	unsigned char	arg_type;
	unsigned int	sum;
	int				i;

	if (!g_op[car->op][C_BYTE])
		return (get_argument_wo_cbyte(info, car));
	i = 1;
	sum = 0;
	while (i < n)
	{
		arg_type = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], i);
		sum += cast_arg_type_to_bytes(arg_type, car->op);
		i++;
	}
	arg_type = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], n);
	i = cast_arg_type_to_bytes(arg_type, car->op);
	return (cat_n_bytes(&info->memory[(car->pc + 2 + sum)
				% MEM_SIZE], i, info->memory));
}
