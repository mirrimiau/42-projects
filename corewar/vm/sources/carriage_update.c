/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:30:22 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:30:24 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	jump_and_refresh(t_car *car, t_info *info)
{
	car->pc = (car->pc + car->jump) % MEM_SIZE;
	car->op = info->memory[car->pc];
	if (car->op < 1 || car->op > 0x10)
		return (0);
	car->wait = g_op[car->op][WAIT_TIME];
	return (1);
}

int	calculate_jump(unsigned char c_byte, unsigned char op)
{
	unsigned char	store;
	int				i;
	int				sum;

	if (op < 1 || op > 0x10)
		return (1);
	if (!c_byte)
		return (2);
	i = 3;
	sum = 0;
	store = c_byte;
	while (i >= 0)
	{
		c_byte = store;
		c_byte = c_byte >> (2 * i);
		if (!g_arg_types[op][CRUMBS_IN_BYTE - i - 1])
			break ;
		sum += cast_arg_type_to_bytes(c_byte, op);
		store -= c_byte << (2 * i);
		i--;
	}
	return (sum + 1 + g_op[op][C_BYTE]);
}

void	print_verbose_move(t_car *car, t_info *info)
{
	unsigned int	i;

	if (!car->jump)
		return ;
	ft_printf("ADV %u (0x%04x -> 0x%04x)",
		car->jump, car->pc, (car->pc + car->jump));
	i = 0;
	while (i < car->jump)
	{
		ft_printf(" %02x", info->memory[(car->pc + i) % MEM_SIZE]);
		i++;
	}
	ft_printf(" \n");
}

void	execute_op(t_car *car, t_info *info)
{
	if (car->op > 0 && car->op < 0x11)
	{
		if (g_op[car->op][C_BYTE])
			car->jump = calculate_jump(info->memory[(car->pc + 1) % MEM_SIZE],
					car->op);
		g_op_jump_table[car->op](info, car);
		if ((info->verbose_opts & SHOW_MOVE) && car->op > 0 && car->op < 0x11)
			print_verbose_move(car, info);
	}
	else
		car->jump = 1;
}

void	run_all_cars(t_info *info)
{
	t_car	*car;
	int		flag;

	car = info->liststart;
	while (car)
	{
		flag = 1;
		if (car->wait == 0)
			flag = jump_and_refresh(car, info);
		if (flag)
			car->wait--;
		if (car->wait == 0)
			execute_op(car, info);
		car = car->next;
	}
}
