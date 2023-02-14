/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:51:42 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/25 12:51:44 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	is_integer(char *str)
{
	int		i;
	int		sign;
	long	nb;

	sign = 1;
	i = -1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	nb = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (nb == 0 && i > (0 + (sign < 0)))
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if ((sign < 0 && nb * sign < INT_MIN) || (sign > 0 && nb > INT_MAX))
			return (0);
	}
	if (sign < 0 && i == 1)
		return (0);
	return (1);
}

int	set_player_number(t_options *opts, char *nbr)
{
	int	player_id;

	if (nbr == NULL)
		return (-1);
	if (!is_integer(nbr))
		return (-1);
	player_id = ft_atoi(nbr);
	if (player_id <= 0)
		error_handler(PLAYER_NB_TOO_SMALL, nbr, 0, 0);
	if (player_id > MAX_PLAYERS)
		error_handler(PLAYER_NB_TOO_BIG, nbr, MAX_PLAYERS, 0);
	if (opts->next_id)
		return (-1);
	opts->next_id = player_id;
	return (1);
}
