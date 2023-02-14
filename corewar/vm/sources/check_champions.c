/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:13:21 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/01 15:13:26 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_champions(t_champion ch_list[], int ch_count)
{
	int	i;

	ft_putendl("Introducing contestants...");
	i = -1;
	while (++i < ch_count)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			ch_list[i].id,
			ch_list[i].code_size,
			ch_list[i].name,
			ch_list[i].comment);
	}
}

void	check_champions(t_champion ch_list[], int ch_count)
{
	int	i;

	i = -1;
	while (++i < ch_count)
	{
		if (!ch_list[i].id)
			error_handler(NON_SEQUENTIAL_NUMBERS, NULL, 0, 0);
	}
	print_champions(ch_list, ch_count);
}
