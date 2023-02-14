/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:03:01 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/02 16:03:03 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_positions(int positions[], int count)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < count)
		positions[i] = pos + MEM_SIZE / count * i;
}

void	deploy_champions(unsigned char memory[],
			t_champion ch_list[], int count)
{
	int	i;
	int	positions[MAX_PLAYERS];

	get_positions(positions, count);
	i = -1;
	while (++i < count)
		ft_memcpy(&memory[positions[i]], ch_list[i].code, ch_list[i].code_size);
}
