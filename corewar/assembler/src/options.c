/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:39 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 15:42:12 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	set_flag(t_flag *flag, char *arg_ptr)
{
	char	*p;

	p = ft_strchr(ASM_FLAGS, *arg_ptr++);
	if (!p || *arg_ptr)
		return (-1);
	if (*p == 'd')
		*flag = DEBUG;
	return (1);
}

int	init_options(t_flag *flag, int argc, char **argv)
{
	char	*p;

	if (argc == 1)
		panic(ASM_USAGE);
	*flag = NONE;
	if (argc == 2)
		return (1);
	if (argc > 3)
		panic("Error: Too many arguments.");
	p = argv[1];
	if (*p++ != '-')
		panic("Error: Invalid option.");
	if (*p == 'h')
		return (0);
	if (set_flag(flag, p) < 0)
		return (0);
	return (1);
}
