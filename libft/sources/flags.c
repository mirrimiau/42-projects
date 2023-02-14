/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:56:40 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 20:56:41 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_minus_and_plus(char **c, t_option *data)
{
	if (**c == '-')
	{
		data->minus++;
		(*c)++;
		return (1);
	}
	else if (**c == '+')
	{
		data->plus++;
		(*c)++;
		if (data->space != 0)
		{
			data->plus += data->space;
			data->space = 0;
		}
		return (1);
	}
	return (0);
}

int	check_space_zero_and_hash(char **c, t_option *data)
{
	if (**c == ' ')
	{
		(*c)++;
		if (data->plus == 0)
			data->space++;
		else
			data->plus++;
		return (1);
	}
	else if (**c == '0')
	{
		data->zero++;
		(*c)++;
		return (1);
	}
	else if (**c == '#')
	{
		data->hash++;
		(*c)++;
		return (1);
	}
	return (0);
}

int	check_known_flags(char *c, va_list ap, t_option *data, char print[10000])
{
	while (1)
	{
		if (check_minus_and_plus(&c, data))
			continue ;
		else if (check_space_zero_and_hash(&c, data))
			continue ;
		break ;
	}
	return (check_known_width(c, ap, data, print));
}
