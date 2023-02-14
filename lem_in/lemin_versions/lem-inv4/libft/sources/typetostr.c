/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:28:26 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/03 15:28:27 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	uint_len_base_x(unsigned long n, const int x)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= x;
		i++;
	}
	return (i);
}

void	nonzero_precision(t_doubledata d, int precision, char ret[100])
{
	ft_strcat(ret, ".");
	while (precision > 0)
	{
		d.dpart *= 10;
		if (d.dpart < 1)
			ft_strcat(ret, "0");
		precision--;
	}
	if (d.dpart - (int) d.dpart > 0.5)
		d.dpart++;
	d.f_itoa = ft_itoa((int) d.dpart);
	ft_strcat(ret, d.f_itoa);
	free (d.f_itoa);
	if (d.dpart == 0 || d.copy > 9)
	{
		if (d.copy > 9 && d.dpart != 0)
			precision = 9;
		while (precision < d.copy)
		{
			ret[d.len + 1 + precision] = '0';
			precision++;
		}
	}
	ret[d.len + d.copy + 1] = '\0';
}

void	long_double_to_str(const long double f, int precision,
			int hash, char ret[100])
{
	t_doubledata	d;

	ft_bzero(ret, 100);
	d.dpart = f - (long double)((unsigned long)f);
	d.len = uint_len_base_x((int)f, 10);
	d.copy = precision;
	if (precision > 9)
		precision = 9;
	d.f_itoa = ft_itoa((int)f);
	ft_strcpy(ret, d.f_itoa);
	free(d.f_itoa);
	if (precision > 0 || hash == 1)
	{
		nonzero_precision(d, precision, ret);
	}
	else
		ret[d.len] = '\0';
}

void	uitoa_base_x_cont(unsigned long number, char fresh[100],
			size_t i, t_option *data)
{
	fresh[i] = '\0';
	if (number == 0)
		fresh[0] = '0';
	--i;
	while (number > 0)
	{
		if ((number % data->base) < 10)
			fresh[i] = (char)(number % data->base) + '0';
		else
			fresh[i] = 'a' - 10 + (char)(number % data->base);
		number /= data->base;
		--i;
	}
	if (data->cap_x)
	{
		i = -1;
		while (fresh[++i])
			fresh[i] = ft_toupper(fresh[i]);
	}
}

void	uitoa_base_x(unsigned long n, const int x,
			t_option *data, char fresh[100])
{
	size_t			i;

	ft_bzero(fresh, 100);
	if ((n == 0 != 0 && x == 16 && data->precision == 0)
		|| (n == 0 && data->precision == 0 && data->hash == 0))
	{
		ft_strcpy(fresh, "\0");
		return ;
	}
	i = uint_len_base_x(n, x);
	if ((int) i <= data->precision)
	{
		ft_memset(fresh, '0', data->precision);
		i = data->precision;
	}
	else if ((int) i <= data->width && data->precision == -1
		&& data->zero != 0 && data->minus == 0)
	{
		ft_memset(fresh, '0', data->width - data->negative
			- data->positive - data->hash_len - data->space);
		i = data->width - data->negative - data->positive - data->hash_len;
	}
	data->base = x;
	uitoa_base_x_cont(n, fresh, i, data);
}
