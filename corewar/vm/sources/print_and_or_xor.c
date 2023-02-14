/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_or_xor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:53 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:51:53 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_and(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("and %d %d r%hhd\n",
		args[0],
		args[1],
		args[2]);
}

void	print_or(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("or %d %d r%hhd\n",
		args[0],
		args[1],
		args[2]);
}

void	print_xor(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("xor %d %d r%hhd\n",
		args[0],
		args[1],
		args[2]);
}
