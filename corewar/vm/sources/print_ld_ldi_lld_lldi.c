/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld_ldi_lld_lldi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:08 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:52:09 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

#define RIGHTMOST_TWO_BYTES 0xFFFF0000

void	print_ld(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("ld %d r%hhd\n", args[0], args[1]);
}

void	print_ldi(t_car *car, int args[])
{
	int		sum;
	short	target_adr;

	sum = args[0] + args[1];
	target_adr = car->pc + sum % IDX_MOD;
	print_process_id(car->index);
	ft_printf("ldi %d %d r%hhd\n", args[0], args[1], args[2]);
	ft_printf("%7c| -> load from %d + %d = %d (with pc and mod %hd)\n",
		' ', args[0], args[1], sum, target_adr);
}

void	print_lld(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("lld %d r%hhd\n", args[0], args[1]);
}

void	print_lldi(t_car *car, int args[])
{
	int				sum;
	unsigned int	with_pc;

	print_process_id(car->index);
	ft_printf("lldi %d %d r%hhd\n", args[0], args[1], args[2]);
	sum = args[0] + args[1];
	with_pc = car->pc + sum;
	ft_printf("%7c| -> load from %d + %d = %d (with pc %u)\n",
		' ', args[0], args[1], sum, with_pc);
}
