/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:53:05 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/08 15:53:06 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decide_solver(int argc, char a[BUF][12], char b[BUF][12])
{
	int	i;

	i = 0;
	while (a[i + 1][0])
	{
		if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
			break ;
		if (!a[i + 2][0])
			return ;
		i++;
	}
	if (argc < 3)
		return ;
	else if (argc == 3)
		solve_twostack(a);
	else if (argc == 4)
		solve_threestack(a);
	else if (argc < 7)
		solve_fivestack(a, b);
	else
		solve_largestack(a, b);
}

int	main(int argc, char **argv)
{
	char	a[BUF][12];
	char	b[BUF][12];
	int		ret;

	if (argc < 2)
	{
		ft_printf("\n");
		return (0);
	}
	ft_bzero(a, BUF * 10);
	ft_bzero(b, BUF * 10);
	if (argc == 2)
		ret = write_a_single_arg(a, &argc, argv[1]);
	else
		ret = write_a(a, argc, argv);
	if (!ret)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	decide_solver(argc, a, b);
	return (0);
}
