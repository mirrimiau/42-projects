/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:16:55 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:16:56 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	copy_parent_reg(t_car *dest, t_car *parent)
{
	int	i;

	i = 1;
	while (i <= REG_NUMBER + 1)
	{
		dest->reg[i] = parent->reg[i];
		i++;
	}
}

static void	init_car(t_car *car, t_info *info, t_car *parent, int forkjump)
{
	car->index = info->next_car_index;
	info->next_car_index++;
	ft_bzero(car->reg, REG_SIZE * (REG_NUMBER + 1));
	if (!parent)
	{
		car->reg[1] = MAX_UINT - car->index + 1;
		car->pc = ((MEM_SIZE / info->champion_count)
				* (car->index - 1)) % MEM_SIZE;
		car->last_live = 0;
		car->carry = 0;
	}
	else
	{
		copy_parent_reg(car, parent);
		car->pc = (parent->pc + forkjump) % MEM_SIZE;
		car->last_live = parent->last_live;
		car->carry = parent->carry;
	}
	car->wait = 0;
	car->jump = 0;
	car->alive = 1;
}

void	push_new_car(t_info *info, t_car *parent, int forkjump)
{
	t_car	*fresh;

	fresh = (t_car *) malloc(sizeof(t_car));
	if (!fresh)
		error_handler(MALLOC_PREFIX, strerror(errno), 0, 0);
	init_car(fresh, info, parent, forkjump);
	fresh->next = info->liststart;
	info->liststart = fresh;
}

void	init_pregame_cars(t_info *info)
{
	int		players;

	players = info->champion_count;
	info->liststart = NULL;
	while (players > 0)
	{
		push_new_car(info, NULL, 0);
		players--;
	}
}
