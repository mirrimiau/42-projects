/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:45:24 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 18:45:25 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	background_rgbw_attributes(char **c)
{
	if (**c == 'r')
	{
		(*c)++;
		ft_putstr("\x1b[101m");
		return (1);
	}
	else if (**c == 'g')
	{
		(*c)++;
		ft_putstr("\x1b[102m");
		return (1);
	}
	else if (**c == 'b')
	{
		(*c)++;
		ft_putstr("\x1b[104m");
		return (1);
	}
	else if (**c == 'w')
	{
		(*c)++;
		ft_putstr("\x1b[107m");
		return (1);
	}
	return (0);
}

int	background_cmyk_attributes(char **c)
{
	if (**c == 'c')
	{
		(*c)++;
		ft_putstr("\x1b[106m");
		return (1);
	}
	else if (**c == 'm')
	{
		(*c)++;
		ft_putstr("\x1b[105m");
		return (1);
	}
	else if (**c == 'y')
	{
		(*c)++;
		ft_putstr("\x1b[103m");
		return (1);
	}
	else if (**c == 'k')
	{
		(*c)++;
		ft_putstr("\x1b[100m");
		return (1);
	}
	return (0);
}

int	background_cap_rgbw_attributes(char **c)
{
	if (**c == 'R')
	{
		(*c)++;
		ft_putstr("\x1b[41m");
		return (1);
	}
	else if (**c == 'G')
	{
		(*c)++;
		ft_putstr("\x1b[42m");
		return (1);
	}
	else if (**c == 'B')
	{
		(*c)++;
		ft_putstr("\x1b[44m");
		return (1);
	}
	else if (**c == 'W')
	{
		(*c)++;
		ft_putstr("\x1b[47m");
		return (1);
	}
	return (0);
}

int	background_cap_cmyk_attributes(char **c)
{
	if (**c == 'C')
	{
		(*c)++;
		ft_putstr("\x1b[46m");
		return (1);
	}
	else if (**c == 'M')
	{
		(*c)++;
		ft_putstr("\x1b[45m");
		return (1);
	}
	else if (**c == 'Y')
	{
		(*c)++;
		ft_putstr("\x1b[43m");
		return (1);
	}
	else if (**c == 'K')
	{
		(*c)++;
		ft_putstr("\x1b[40m");
		return (1);
	}
	return (0);
}
