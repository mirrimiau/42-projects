/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:01 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/17 14:46:03 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resolve_specifier_s(va_list ap, t_option *data,
		char print[10000])
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		ft_strcat(print, "(null)");
		return ;
	}
	if (data->precision == -1)
		ft_strcat(print, s);
	else
		ft_strncat(print, s, data->precision);
}
