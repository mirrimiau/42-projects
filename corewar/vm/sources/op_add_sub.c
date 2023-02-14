/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:02:33 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:02:36 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_add(t_info *info, t_car *car)
{
	unsigned int	args[3];
	unsigned int	sum;

	ft_bzero(args, sizeof(args));
	if (get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1) != REG_CODE
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2) != REG_CODE
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3) != REG_CODE)
		return ;
	args[0] = get_argument(info, 1, car);
	args[1] = get_argument(info, 2, car);
	args[2] = get_argument(info, 3, car);
	if ((args[0] > REG_NUMBER || args[0] < 0x01)
		|| (args[1] > REG_NUMBER || args[1] < 0x01)
		|| (args[2] > REG_NUMBER || args[2] < 0x01))
		return ;
	sum = car->reg[args[0]] + car->reg[args[1]];
	car->reg[args[2]] = sum;
	car->carry = 0;
	if (!sum)
		car->carry = 1;
	if (info->verbose_opts & SHOW_OP)
		print_add(car, args);
}

void	op_sub(t_info *info, t_car *car)
{
	unsigned int	args[3];
	unsigned int	sub;

	ft_bzero(args, sizeof(args));
	if (get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1) != REG_CODE
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2) != REG_CODE
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3) != REG_CODE)
		return ;
	args[0] = get_argument(info, 1, car);
	args[1] = get_argument(info, 2, car);
	args[2] = get_argument(info, 3, car);
	if ((args[0] > REG_NUMBER || args[0] < 0x01)
		|| (args[1] > REG_NUMBER || args[1] < 0x01)
		|| (args[2] > REG_NUMBER || args[2] < 0x01))
		return ;
	sub = car->reg[args[0]] - car->reg[args[1]];
	car->reg[args[2]] = sub;
	car->carry = 0;
	if (!sub)
		car->carry = 1;
	if (info->verbose_opts & SHOW_OP)
		print_sub(car, args);
}
