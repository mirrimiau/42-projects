/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp_fork_lfork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:20 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:05:22 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_zjmp(t_info *info, t_car *car)
{
	unsigned int	arg;

	car->jump = 3;
	arg = get_argument(info, 1, car);
	if (car->carry)
		car->pc = (car->pc + ((short)arg % IDX_MOD)) % MEM_SIZE;
	else
	{
		if (info->verbose_opts & SHOW_OP)
			print_zjmp(car, arg, 0);
		return ;
	}
	if (info->verbose_opts & SHOW_OP)
		print_zjmp(car, arg, 1);
	car->jump = 0;
	car->wait = 0;
}

void	op_fork(t_info *info, t_car *car)
{
	unsigned int	arg;

	arg = get_argument(info, 1, car);
	push_new_car(info, car, ((short)arg % IDX_MOD));
	if (info->verbose_opts & SHOW_OP)
		print_fork(car, arg);
	car->jump = 3;
}

void	op_lfork(t_info *info, t_car *car)
{
	unsigned int	arg;

	arg = get_argument(info, 1, car);
	push_new_car(info, car, (short)arg);
	if (info->verbose_opts & SHOW_OP)
		print_lfork(car, arg);
	car->jump = 3;
}
