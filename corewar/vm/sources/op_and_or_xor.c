/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and_or_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:03:18 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:03:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	save_and_check_args(t_info *info, t_car *car,
	unsigned char arg_types[], unsigned int args[])
{
	args[0] = get_argument(info, 1, car);
	if (arg_types[0] == REG_CODE)
	{
		if (args[0] > REG_NUMBER || args[0] < 0x01)
			return (-1);
		args[0] = car->reg[args[0]];
	}
	else if (arg_types[0] == IND_CODE)
		args[0] = cat_n_bytes(&info->memory[(car->pc + (short)args[0] % IDX_MOD)
				% MEM_SIZE], REG_SIZE, info->memory);
	args[1] = get_argument(info, 2, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || args[1] < 0x01)
			return (-1);
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
		args[1] = cat_n_bytes(&info->memory[(car->pc + (short)args[1] % IDX_MOD)
				% MEM_SIZE], REG_SIZE, info->memory);
	args[2] = get_argument(info, 3, car);
	if (args[2] > REG_NUMBER || !args[2])
		return (-1);
	return (1);
}

void	op_and(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (!arg_types[0] || !arg_types[1] || arg_types[2] != REG_CODE)
		return ;
	if (save_and_check_args(info, car, arg_types, args) == -1)
		return ;
	if (info->verbose_opts & SHOW_OP)
		print_and(car, args);
	car->reg[args[2]] = args[0] & args[1];
	car->carry = 0;
	if (!car->reg[args[2]])
		car->carry = 1;
}

void	op_or(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (!arg_types[0] || !arg_types[1] || arg_types[2] != REG_CODE)
		return ;
	if (save_and_check_args(info, car, arg_types, args) == -1)
		return ;
	if (info->verbose_opts & SHOW_OP)
		print_or(car, args);
	car->reg[args[2]] = args[0] | args[1];
	car->carry = 0;
	if (!car->reg[args[2]])
		car->carry = 1;
}

void	op_xor(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (!arg_types[0] || !arg_types[1] || arg_types[2] != REG_CODE)
		return ;
	if (save_and_check_args(info, car, arg_types, args) == -1)
		return ;
	if (info->verbose_opts & SHOW_OP)
		print_xor(car, args);
	car->reg[args[2]] = args[0] ^ args[1];
	car->carry = 0;
	if (!car->reg[args[2]])
		car->carry = 1;
}
