/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:10:07 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/07 12:10:08 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate_db(int *argc, char **argv, int *debugmode)
{
	if (ft_strequ(argv[1], "-v"))
	{
		(*argc)--;
		*debugmode = 1;
		ft_printf("%{aB}s", "\t");
		ft_printf("%{W}s", "DEBUGGING MODE");
		ft_printf("%{O}s\n\n", " ");
	}
}

int	main(int argc, char **argv)
{
	char	a[BUF][12];
	char	b[BUF][12];
	int		ret;
	int		debugmode;

	if (argc < 2)
		return (0);
	debugmode = 0;
	initiate_db(&argc, argv, &debugmode);
	ft_bzero(a, BUF * 12);
	ft_bzero(b, BUF * 12);
	if (argc == 2)
		ret = write_a_single_arg(a, &argc, argv[1 + debugmode]);
	else
		ret = write_a(a, argc, argv + debugmode);
	if (!ret)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ret = commands(a, b, debugmode);
	if (!ret)
		write(2, "Error\n", 6);
	check_ok(a, b[0][0]);
	return (0);
}
