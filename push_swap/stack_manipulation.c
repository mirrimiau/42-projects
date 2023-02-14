/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:05:18 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/10 16:05:20 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	commands(char a[BUF][12], char b[BUF][12], int debugmode)
{
	int		ret;
	char	input[BUF];
	int		fd;
	t_link	*sorted;

	sorted = create_sorted_link(a);
	fd = open("txt", O_WRONLY);
	while (1)
	{
		ret = read(0, input, BUF);
		write (fd, input, ft_strlen(input));
		if (ret == 0)
		{
			ret = 1;
			break ;
		}
		ret = resolve_input(input, a, b);
		if (ret < 1)
			break ;
		ft_bzero(input, BUF);
		if (debugmode == 1)
			print_db_data(a, b, sorted);
	}
	free_links(sorted);
	return (ret);
}

int	arg_is_numbers(t_writing_var var, char **argv)
{
	var.j = 0;
	while (argv[var.i + 1][var.j])
	{
		if (!ft_isdigit(argv[var.i + 1][var.j]) &&
			(var.j != 0 && argv[var.i + 1][var.j] != '-'))
			return (0);
		var.j++;
		if (var.j > 11)
			return (0);
	}
	if (var.j == 11 || (var.j == 10 && argv[var.i][0] != '-'))
		return (test_bounds(argv[var.i + 1]));
	return (1);
}

int	write_a(char a[BUF][12], int argc, char **argv)
{
	t_writing_var	var;

	var.i = 0;
	while (var.i + 1 < argc)
	{
		if (!arg_is_numbers(var, argv))
			return (0);
		var.j = ft_atoi(argv[var.i + 1]);
		var.temp = ft_itoa(var.j);
		ft_strcpy(a[var.i], var.temp);
		free(var.temp);
		var.j = 0;
		while (var.j < var.i)
		{
			if (ft_strequ(a[var.i], a[var.j]))
				return (0);
			var.j++;
		}
		if (a[var.i])
		var.i++;
	}
	return (1);
}

void	check_ok(char a[BUF][12], char b)
{
	int	i;

	if (b != '\0')
	{
		ft_printf("KO\n");
		return ;
	}
	i = 0;
	while (a[i][0] && a[i + 1][0])
	{
		if (atoi(a[i]) > atoi(a[i + 1]))
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
}

int	write_a_single_arg(char a[BUF][12], int *argc, char *s)
{
	char	**split;
	int		i;
	int		ret;

	if (!ft_isdigit(*s) && *s != '-')
		return (0);
	i = 0;
	split = ft_strsplit(s, ' ');
	while (split[i])
		i++;
	split[i] = ft_strdup(split[0]);
	if (split[i] == NULL)
		return (0);
	ret = write_a(a, i + 1, split);
	reverse_rotate(a);
	*argc = i + 1;
	while (i >= 0)
	{
		free (split[i]);
		i--;
	}
	free (split);
	return (ret);
}
