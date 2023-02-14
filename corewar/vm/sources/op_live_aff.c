/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:59:35 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 11:59:38 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_live(t_info *info, t_car *car)
{
	unsigned int	arg;

	car->jump = 1 + REG_SIZE;
	car->last_live = info->cycle;
	info->lives_this_check++;
	arg = cat_n_bytes(&info->memory[(car->pc + 1) % MEM_SIZE], REG_SIZE,
			info->memory);
	if (info->verbose_opts & SHOW_OP)
		print_live(car, arg);
	if (arg && (0x00 - arg) <= (unsigned int)info->champion_count)
	{
		info->last_live_champ = 0x00 - arg;
		if (info->verbose_opts & SHOW_ALIVE)
			ft_printf("Player %i (%s) is said to be alive\n", 0x00 - arg,
				info->champions[0x00 - arg - 1].name);
	}
}

void	op_aff(t_info *info, t_car *car)
{
	unsigned char	arg_type;
	unsigned int	reg;
	char			value;

	if (info->aff_flag)
	{
		arg_type = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
		reg = get_argument(info, 1, car);
		if (arg_type != REG_CODE || reg < 1 || reg > 0x10)
			return ;
		value = (char)car->reg[reg];
		if (info->verbose_opts & SHOW_OP)
			print_aff(car, reg);
		ft_putstr("Aff: ");
		write(1, &value, 1);
		ft_putchar('\n');
	}
}
