/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:07:06 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 18:07:11 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	basic_attributes(char **c)
{
	if (**c == '1')
	{
		(*c)++;
		ft_putstr("\x1b[1m");
		return (1);
	}
	else if (**c == '2')
	{
		(*c)++;
		ft_putstr("\x1b[4m");
		return (1);
	}
	else if (**c == '3')
	{
		(*c)++;
		ft_putstr("\x1b[5m");
		return (1);
	}
	else if (**c == 'O')
	{
		(*c)++;
		ft_putstr("\x1b[0m");
		return (1);
	}
	return (0);
}

int	rgbw_attributes(char **c)
{
	if (**c == 'r')
	{
		(*c)++;
		ft_putstr("\x1b[91m");
		return (1);
	}
	else if (**c == 'g')
	{
		(*c)++;
		ft_putstr("\x1b[92m");
		return (1);
	}
	else if (**c == 'b')
	{
		(*c)++;
		ft_putstr("\x1b[94m");
		return (1);
	}
	else if (**c == 'w')
	{
		(*c)++;
		ft_putstr("\x1b[97m");
		return (1);
	}
	return (0);
}

int	cmyk_attributes(char **c)
{
	if (**c == 'c')
	{
		(*c)++;
		ft_putstr("\x1b[96m");
		return (1);
	}
	else if (**c == 'm')
	{
		(*c)++;
		ft_putstr("\x1b[95m");
		return (1);
	}
	else if (**c == 'y')
	{
		(*c)++;
		ft_putstr("\x1b[93m");
		return (1);
	}
	else if (**c == 'k')
	{
		(*c)++;
		ft_putstr("\x1b[90m");
		return (1);
	}
	return (0);
}

int	cap_rgbw_attributes(char **c)
{
	if (**c == 'R')
	{
		(*c)++;
		ft_putstr("\x1b[31m");
		return (1);
	}
	else if (**c == 'G')
	{
		(*c)++;
		ft_putstr("\x1b[32m");
		return (1);
	}
	else if (**c == 'B')
	{
		(*c)++;
		ft_putstr("\x1b[34m");
		return (1);
	}
	else if (**c == 'W')
	{
		(*c)++;
		ft_putstr("\x1b[37m");
		return (1);
	}
	return (0);
}

int	cap_cmyk_attributes(char **c)
{
	if (**c == 'C')
	{
		(*c)++;
		ft_putstr("\x1b[36m");
		return (1);
	}
	else if (**c == 'M')
	{
		(*c)++;
		ft_putstr("\x1b[35m");
		return (1);
	}
	else if (**c == 'Y')
	{
		(*c)++;
		ft_putstr("\x1b[33m");
		return (1);
	}
	else if (**c == 'K')
	{
		(*c)++;
		ft_putstr("\x1b[30m");
		return (1);
	}
	return (0);
}
