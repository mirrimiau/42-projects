/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:43:15 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 19:43:16 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
    A field width or precision, or both, may be indicated by an asterisk `*' 
	or an asterisk followed by one or more decimal digits and a `$' instead of
	a digit string.  In this case, an int argument supplies the field width or
	precision.  A negative field width is treated as a left adjustment flag
	followed by a positive field width; a negative precision is treated
	as though it were missing.  If a single format directive mixes
	positional (nn$) and non-positional arguments, the results are undefined. 
*/
void	resolve_asterisk_width(char *c, va_list ap, t_option *data)
{
	int		i;
	int		arg;

	i = 0;
	if (c[i] == '$')
	{
		data->dollar++;
		return ;
	}
	if (c[i] == '-')
		i++;
	while (ft_isdigit(c[i]))
		i++;
	if (!check_asterisk_dollarsign_and_nonzero(c, ap, data, &i))
	{
		arg = va_arg(ap, int);
		if (arg < 0)
		{
			data->minus++;
			data->dollar--;
			arg *= -1;
		}
			data->width = arg;
	}
}

void	resolve_width(t_option *data, char print[10000])
{
	int	i;

	i = ft_strlen(print);
	if ((int) ft_strlen(print) < data->width)
	{
		if (data->minus != 0)
		{
			while ((int) ft_strlen(print) < data->width)
				ft_strcat(print, " ");
		}
		else if (data->zero != 0 && data->precision == -1)
		{
			ft_memmove(print + (data->width - ft_strlen(print)),
				print, ft_strlen(print));
			ft_memset(print, '0', data->width - i);
		}
		else
		{
			ft_memmove(print + (data->width - ft_strlen(print)),
				print, ft_strlen(print));
			ft_memset(print, ' ', data->width - i);
		}
	}
}

int	check_known_width(char *c, va_list ap, t_option *data, char print[10000])
{
	if (*c == '*')
	{
		c++;
		data->asterisk++;
		resolve_asterisk_width(c, ap, data);
		c += data->minus + data->width_len + data->dollar;
	}
	else if (ft_isdigit(*c))
	{
		data->width = ft_atoi(c);
		data->width_len = uint_len_base_x(data->width, 10);
		c += data->width_len;
	}
	return (check_known_precision(c, ap, data, print));
}
