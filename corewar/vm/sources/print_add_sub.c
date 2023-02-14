/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:35 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:51:37 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_add(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("add r%hhd r%hhd r%hhd\n",
		args[0],
		args[1],
		args[2]);
}

void	print_sub(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("sub r%hhd r%hhd r%hhd\n",
		args[0],
		args[1],
		args[2]);
}
