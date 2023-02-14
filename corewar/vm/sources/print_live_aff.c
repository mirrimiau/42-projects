/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_live_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:20 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:52:21 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_live(t_car *car, unsigned int arg)
{
	print_process_id(car->index);
	ft_printf("live %d\n", (int)arg);
}

void	print_aff(t_car *car, unsigned int arg)
{
	print_process_id(car->index);
	ft_printf("aff r%hhd\n", arg);
}
