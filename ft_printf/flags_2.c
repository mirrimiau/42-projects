/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:09:08 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 21:09:12 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resolve_plus(long long n, t_option *data, char print[10000])
{
	if (n >= 0 && data->plus)
	{
		data->positive++;
		ft_strcat(print, "+");
	}
}

void	resolve_hash(long long n, t_option *data, int x, char print[10000])
{
	if (data->hash == 1 && n != 0)
	{
		if (x == 8)
			ft_strcat(print, "0");
		else if (x == 16 && data->cap_x)
		{
			ft_strcat(print, "0X");
			data->hash_len = 2;
		}
		else if (x == 16)
		{
			ft_strcat(print, "0x");
			data->hash_len = 2;
		}
	}
}

void	resolve_flags(long long n, t_option *data, int x, char print[10000])
{
	resolve_hash(n, data, x, print);
	resolve_plus(n, data, print);
}

void	resolve_space(long long n, long double f,
			t_option *data, char print[10000])
{
	if ((n >= 0 || f >= 0) && data->plus != 1 && data->space != 0)
		ft_strcat(print, " ");
}
