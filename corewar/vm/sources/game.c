/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:39:37 by mapostol          #+#    #+#             */
/*   Updated: 2022/11/03 13:39:39 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	declare_winner(t_info *info)
{
	t_champion	winner;
	int			i;

	winner = info->champions[0];
	i = 1;
	while (i < info->champion_count)
	{
		if (info->last_live_champ == (unsigned int) info->champions[i].id)
			winner = info->champions[i];
		i++;
	}
	ft_printf("Contestant %i, \"%s\", has won !\n", winner.id, winner.name);
	return (1);
}

void	init_vars(t_info *info)
{
	info->cycle = 1;
	info->cycles_to_die = CYCLE_TO_DIE;
	info->next_check_cycle = CYCLE_TO_DIE;
	info->lives_this_check = 0;
	info->checks_after_mod = 0;
	info->last_live_champ = 1;
	info->next_car_index = 1;
}

int	run_game(t_info *info)
{
	init_vars(info);
	init_pregame_cars(info);
	if (!info->dump_cycles)
		print_memory(info->memory, info->dump_line_len);
	while (1)
	{
		if (info->verbose_opts & SHOW_CYCLE)
			ft_printf("It is now cycle %u\n", info->cycle);
		run_all_cars(info);
		if (info->cycle == info->next_check_cycle || info->cycles_to_die < 1)
			check_aliveness(info);
		if (no_cars_alive(info))
			return (declare_winner(info));
		if ((int)info->cycle == info->dump_cycles)
			print_memory(info->memory, info->dump_line_len);
		info->cycle++;
	}
}
