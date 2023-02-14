/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_auxiliaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:40:39 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	no_cars_alive(t_info *info)
{
	t_car	*car;

	car = info->liststart;
	while (car)
	{
		if (car->alive)
			return (0);
		car = car->next;
	}
	return (1);
}

t_car	*free_car(t_car *dead, t_car *prev, t_info *info)
{
	t_car	*next;

	if (info->verbose_opts & SHOW_DEATH)
		ft_printf("Process %u hasn't lived for %i cycles (CTD %i)\n",
			dead->index, info->cycle - dead->last_live,
			info->cycles_to_die);
	next = dead->next;
	if (dead)
		free(dead);
	if (!prev)
		info->liststart = next;
	else
		prev->next = next;
	return (prev);
}

void	reduce_cycle_to_die(t_info *info)
{
	info->cycles_to_die -= CYCLE_DELTA;
	info->checks_after_mod = 0;
	if (info->verbose_opts & SHOW_CYCLE)
		ft_printf("Cycle to die is now %i\n", info->cycles_to_die);
}

void	check_aliveness(t_info *info)
{
	t_car	*car;
	t_car	*prev;

	car = info->liststart;
	prev = NULL;
	while (car)
	{
		if (info->cycles_to_die < 1
			|| info->cycle - info->cycles_to_die >= car->last_live)
			car = free_car(car, prev, info);
		if (!car)
			return (check_aliveness(info));
		prev = car;
		car = car->next;
	}
	info->checks_after_mod++;
	if (info->lives_this_check >= NBR_LIVE
		|| info->checks_after_mod >= MAX_CHECKS)
		reduce_cycle_to_die(info);
	info->next_check_cycle = info->cycle + info->cycles_to_die;
	info->lives_this_check = 0;
}
