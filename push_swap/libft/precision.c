/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:20:42 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 20:20:44 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	asterisk_precision_dollarsign(char *c, va_list ap, t_option *data,
			int *i)
{
	va_list	copy;
	int		arg;

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
	if (*i < 0)
	{
		*i *= -1;
		data->precision_len += 1 + uint_len_base_x(*i, 10);
	}
	else
	{
		data->precision = *i;
		data->precision_len += 1 + uint_len_base_x(*i, 10);
	}
}

void	asterisk_precision_nonzero(char *c, va_list ap, t_option *data,
			int *i)
{
	int	arg;

	*i = ft_atoi(c);
	arg = va_arg(ap, int);
	if (*i < 0)
	{
		data->minus++;
		*i *= -1;
		data->precision = *i;
		data->precision_len += uint_len_base_x(*i, 10) + 1;
	}
	else if (arg < 0)
	{
		data->minus++;
		data->dollar--;
		data->precision = *i;
		data->precision_len += uint_len_base_x(*i, 10) + 1;
	}
	else
	{
		data->precision = arg;
		data->precision_len += uint_len_base_x(*i, 10) + 1;
	}
}

void	resolve_precision_dollarsign_and_nonzero(char *c, va_list ap,
			t_option *data, int *i)
{
	int	arg;

	if (c[*i] == '$')
		asterisk_precision_dollarsign(c, ap, data, i);
	else if (ft_atoi(c))
		asterisk_precision_nonzero(c, ap, data, i);
	else
	{
		arg = va_arg(ap, int);
		if (arg < 0)
		{
			data->minus++;
			data->dollar--;
			arg *= -1;
		}
			data->precision = arg;
			data->precision_len++;
	}	
}

void	resolve_asterisk_precision(char *c, va_list ap, t_option *data)
{
	int		i;

	i = 0;
	if (c[i] == '$' || c[i] == '-')
	{
		data->dollar++;
		data->precision_len = 1;
		return ;
	}
	while (ft_isdigit(c[i]))
		i++;
	resolve_precision_dollarsign_and_nonzero(c, ap, data, &i);
}

int	check_known_precision(char *c, va_list ap, t_option *data,
		char print[10000])
{
	if (*c != '.')
		return (check_known_length(c, ap, data, print));
	c++;
	if (*c == '*')
	{
		c++;
		data->asterisk++;
		resolve_asterisk_precision(c, ap, data);
		c += data-> minus + data->precision_len + data->dollar - 1;
		return (check_known_length(c, ap, data, print));
	}
	else if (!ft_isdigit(*c))
	{
		data->precision = 0;
		data->precision_len--;
	}
	else if (*c == '0')
		data->precision = 0;
	else
	{
		data->precision = ft_atoi(c);
	}
	data->precision_len += 1 + uint_len_base_x(data->precision, 10);
	c += data->precision_len - 1;
	return (check_known_length(c, ap, data, print));
}
