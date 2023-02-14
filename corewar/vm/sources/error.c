/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:03:04 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/21 16:03:06 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"	

void	print_usage(char *usage)
{
	ft_putendl_fd(usage, 2);
	exit(1);
}

void	error_handler(char *message, char *arg1,
	unsigned int arg2, unsigned int arg3)
{
	ft_putstr_fd("Error: ", 2);
	ft_dprintf(2, message, arg1, arg2, arg3);
	ft_putchar_fd('\n', 2);
	exit(1);
}
