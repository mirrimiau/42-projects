/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:29:02 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 14:05:31 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	t_flag	f;
	t_sh	d;

	if (!init_options(&f, argc, argv) || !valid_file(argc, argv[2 - 1 * !(f)]))
		panic(ASM_USAGE);
	parse(&d, &f, argv[2 - 1 * !(f)]);
	assemble(&d, argv[2 - 1 * !(f)]);
	return (0);
}
