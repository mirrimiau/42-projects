/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:11:47 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 21:11:48 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifiers_cs(char c, va_list ap,
		t_option *data, char print[10000])
{
	char	character;

	if (c == 'c')
	{
		character = va_arg(ap, int);
		if (character == 0 && data->width < 1)
			data->null_char++;
		print[0] = character;
		return (1);
	}
	if (c == 's')
	{
		resolve_specifier_s(ap, data, print);
		return (1);
	}
	return (0);
}

void	resolve_long_double(va_list ap, t_option *data,
		char print[10000])
{
	long double	lf;
	char		str[100];

	lf = va_arg(ap, long double);
	resolve_space(-1, lf, data, print);
	if (lf < 0)
	{
		lf *= -1;
		ft_strcat(print, "-");
		data->negative = 1;
	}
	long_double_to_str(lf, data->precision, data->hash, str);
	ft_strcat(print, str);
}

int	resolve_specifier_f(va_list ap, t_option *data,
		char print[10000])
{
	double		f;
	char		str[100];

	if (data->precision == -1)
		data->precision = 6;
	if (data->cap_l != 0)
		resolve_long_double(ap, data, print);
	else
	{
		f = va_arg(ap, double);
		resolve_space(-1, f, data, print);
		if (f < 0)
		{
			f *= -1;
			ft_strcat(print, "-");
			data->negative = 1;
		}
		long_double_to_str(f, data->precision, data->hash, str);
		ft_strcat(print, str);
	}
	return (1);
}

int	resolve_specifier_p(va_list ap, t_option *data,
		char print[10000])
{
	int	i;

	data->l++;
	ft_strcat(print, "0x");
	i = specifier_oux_base_x(ap, data, 16, print);
	data->l--;
	return (i);
}

int	check_known_specifiers(char c, va_list ap,
		t_option *data, char print[10000])
{
	int			ret;

	ret = check_specifiers_dioux(c, ap, data, print);
	if (ret)
		return (ret);
	ret = check_specifiers_cs(c, ap, data, print);
	if (ret)
		return (ret);
	if (c == 'p')
		return (resolve_specifier_p(ap, data, print));
	if (c == 'f')
		return (resolve_specifier_f(ap, data, print));
	if (c == '%')
	{
		ft_strncat(print, "%", 1);
		return (1);
	}
	ft_putstr("\n\x1b[5m\x1b[41m(WARNING: Undefined behavior. \
	Argument for ft_printf not supported.)\x1B[0m\n");
	return (0);
}
