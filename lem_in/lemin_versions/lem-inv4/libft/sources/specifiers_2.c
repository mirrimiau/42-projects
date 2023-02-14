/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:42:30 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/17 14:42:32 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_d_i(va_list ap, t_option *data, char print[10000])
{
	long long	lli;
	char		str[100];

	if (data->l == 1)
		lli = va_arg(ap, long);
	else if (data->ll != 0)
		lli = va_arg(ap, long long);
	else
		lli = va_arg(ap, int);
	if (data->hh)
		lli = (signed char) lli;
	if (data->h)
		lli = (short) lli;
	resolve_flags(lli, data, 10, print);
	resolve_space(lli, -1, data, print);
	if (lli < 0)
	{
		ft_strcat(print, "-");
		data->negative = 1;
		lli = -lli;
	}
	uitoa_base_x(lli, 10, data, str);
	ft_strcat(print, str);
	return (1);
}

int	check_oux_l_and_ll(va_list ap, t_option *data, int x, char print[10000])
{
	unsigned long		li;
	unsigned long long	lli;
	char				str[100];

	if (data->l == 1)
	{
		li = va_arg(ap, unsigned long);
		resolve_hash(li, data, x, print);
		uitoa_base_x(li, x, data, str);
		ft_strcat(print, str);
		return (1);
	}
	else if (data->ll != 0)
	{
		lli = va_arg(ap, unsigned long long);
		resolve_hash(lli, data, x, print);
		uitoa_base_x(lli, x, data, str);
		ft_strcat(print, str);
		return (1);
	}
	return (0);
}

int	check_oux_h_and_hh(va_list ap, t_option *data, int x, char print[10000])
{
	unsigned int	i;
	char			str[100];

	i = va_arg(ap, int);
	resolve_hash(i, data, x, print);
	if (data->hh != 0)
	{
		uitoa_base_x((unsigned char) i, x, data, str);
		ft_strcat(print, str);
	}
	else if (data->h != 0)
	{
		uitoa_base_x((unsigned short) i, x, data, str);
		ft_strcat(print, str);
	}
	else
	{
		uitoa_base_x(i, x, data, str);
		ft_strcat(print, str);
	}
	return (1);
}

int	specifier_oux_base_x(va_list ap, t_option *data, int x, char print[10000])
{
	if (check_oux_l_and_ll(ap, data, x, print))
		return (1);
	return (check_oux_h_and_hh(ap, data, x, print));
}

int	check_specifiers_dioux(char c, va_list ap,
		t_option *data, char print[10000])
{
	if (c == 'd' || c == 'i')
		return (specifier_d_i(ap, data, print));
	if (c == 'o')
		return (specifier_oux_base_x(ap, data, 8, print));
	if (c == 'u')
		return (specifier_oux_base_x(ap, data, 10, print));
	if (c == 'x')
	{
		return (specifier_oux_base_x(ap, data, 16, print));
	}
	if (c == 'X')
	{
		data->cap_x = 1;
		return (specifier_oux_base_x(ap, data, 16, print));
	}
	return (0);
}
