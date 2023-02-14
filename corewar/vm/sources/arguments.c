/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:46:17 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/20 17:46:19 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_options(t_info *info, t_options *opts)
{
	info->dump_cycles = opts->dump;
	info->dump_line_len = opts->octets_in_line;
	info->verbose_opts = opts->verbose_flags;
	info->aff_flag = opts->aff_flag;
}

static void	init_options(t_options *opts)
{
	opts->dump = -1;
	opts->octets_in_line = 0;
	opts->next_id = 0;
	opts->verbose_flags = 0;
	opts->aff_flag = 0;
}

static int	get_index(char *opt)
{
	int	i;

	i = -1;
	while (OPTIONS[++i])
	{
		if (OPTIONS[i] == *opt)
			break ;
	}
	if (i == OPTION_COUNT)
		return (-1);
	return (i);
}

static int	read_option(char **argv, int index, t_options *opts)
{
	int	opt_index;
	int	ret;

	if (ft_strlen(&argv[index][1]) != 1)
	{
		if (ft_strncmp("dump", &argv[index][1], 5))
			return (-1);
		ret = set_dump(opts, argv[index + 1]);
		opts->octets_in_line = 32;
	}
	else
	{
		opt_index = get_index(&argv[index][1]);
		if (opt_index == -1)
			return (-1);
		ret = g_jump_table[opt_index](opts, argv[index + 1]);
	}
	if (ret == -1)
		return (-1);
	return (index + ret);
}

int	read_arguments(int argc, char **argv, t_info *info)
{
	t_options	options;
	int			i;

	init_options(&options);
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (options.next_id)
				return (-1);
			i = read_option(argv, i, &options);
			if (i == -1)
				return (-1);
		}
		else
			parse_champion(info, argv[i], &options.next_id);
	}
	if (info->champion_count == 0)
		return (-1);
	set_options(info, &options);
	return (1);
}
