/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_text_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:40:48 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/25 14:40:51 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	set_aff(t_options *opts, char *nbr)
{
	(void)nbr;
	opts->aff_flag = 1;
	return (0);
}

int	set_dump(t_options *opts, char *nbr)
{
	if (nbr == NULL)
		return (-1);
	opts->dump = ft_atoi(nbr);
	opts->octets_in_line = 64;
	return (1);
}

int	set_verbose_flag(t_options *opts, char *nbr)
{
	if (nbr == NULL)
		return (-1);
	opts->verbose_flags += ft_atoi(nbr);
	return (1);
}
