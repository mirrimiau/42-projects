/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:23:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:23:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_process_id(unsigned int id)
{
	ft_printf("P %4u | ", id);
}

void	print_memory(unsigned char memory[], int line_len)
{
	int				i;
	unsigned int	line_count;

	line_count = 0;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % line_len == 0)
			ft_printf("0x%04x : ", line_len * line_count++);
		ft_printf("%02x ", memory[i]);
		if ((i + 1) % line_len == 0)
			ft_putchar('\n');
	}
	exit(0);
}
