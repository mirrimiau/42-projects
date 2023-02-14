/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:15:49 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 20:15:50 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resolve_asterisk_dollarsign(char *c, va_list ap, t_option *data, int *i)
{
	int		arg;
	va_list	copy;

	va_copy(copy, ap);
	data->dollar++;
	arg = ft_atoi(c);
	if (arg > 0)
	{
		while (arg > 0)
		{
			*i = va_arg(copy, int);
			arg--;
		}
	}
	else if (arg < 0)
	{
		data->minus++;
		*i = va_arg(copy, int);
		while (arg < -1)
		{
			va_arg(ap, int);
			arg++;
		}
	}
}

void	resolve_asterisk_nonzero(char *c, va_list ap, t_option *data, int *i)
{
	int	arg;

	*i = ft_atoi(c);
	arg = va_arg(ap, int);
	if (*i < 0)
	{
		data->minus++;
		*i *= -1;
		data->width = *i;
		data->width_len = uint_len_base_x(*i, 10);
	}
	else if (arg < 0)
	{
		data->minus++;
		data->dollar--;
		data->width = *i;
		data->width_len = uint_len_base_x(*i, 10);
	}
	else
	{
		data->width = *i;
		data->width_len = uint_len_base_x(*i, 10);
	}
}

int	check_asterisk_dollarsign_and_nonzero(char *c, va_list ap,
		t_option *data, int *i)
{
	if (c[*i] == '$')
	{
		resolve_asterisk_dollarsign(c, ap, data, i);
		if (*i < 0)
		{
			data->minus++;
			data->dollar--;
			*i *= -1;
		}
		data->width = *i;
		data->width_len = uint_len_base_x(*i, 10);
		return (1);
	}
	else if (ft_atoi(c))
	{
		resolve_asterisk_nonzero(c, ap, data, i);
		return (1);
	}
	return (0);
}
