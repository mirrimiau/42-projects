/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:48:45 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/17 14:48:46 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_length_h_and_l(char **c, t_option *data)
{
	if (**c == 'h')
	{
		(*c)++;
		if (**c == 'h')
		{	
			data->hh = 2;
			(*c)++;
		}
		else
			data->h = 1;
		return (1);
	}
	else if (**c == 'l')
	{
		(*c)++;
		if (**c == 'l')
		{
			data->ll = 2;
			(*c)++;
		}
		else
			data->l = 1;
		return (1);
	}
	return (0);
}

int	check_known_length(char *c, va_list ap, t_option *data, char print[10000])
{
	int	ret;

	ret = check_length_h_and_l(&c, data);
	if (!ret)
	{
		if (*c == 'L')
		{
			data->cap_l = 1;
			c++;
		}
	}
	return (check_known_specifiers(*c, ap, data, print));
}
