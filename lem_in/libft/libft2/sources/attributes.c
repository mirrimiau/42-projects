/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:58:10 by mapostol          #+#    #+#             */
/*   Updated: 2022/02/16 17:58:11 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	background_attributes(char **c)
{
	if (background_rgbw_attributes(c))
		return (1);
	else if (background_cmyk_attributes(c))
		return (1);
	else if (background_cap_rgbw_attributes(c))
		return (1);
	else if (background_cap_cmyk_attributes(c))
		return (1);
	return (0);
}

void	valid_attributes(char **c)
{
	while (1)
	{
		if (basic_attributes(c))
			continue ;
		else if (rgbw_attributes(c))
			continue ;
		else if (cmyk_attributes(c))
			continue ;
		else if (cap_rgbw_attributes(c))
			continue ;
		else if (cap_cmyk_attributes(c))
			continue ;
		else if (**c == 'a')
		{
			(*c)++;
			if (background_attributes(c))
				continue ;
		}
		break ;
	}
}

int	check_known_attributes(char *c, va_list ap,
	t_option *data, char print[10000])
{
	int	i;

	i = 0;
	if (*c == '{')
	{
		while (c[i])
		{
			if (c[i] == '}')
				break ;
			i++;
		}
		if (c[i] == '}')
		{
			c++;
			valid_attributes(&c);
			c++;
			data->attribute += i + 1;
		}
	}
	return (check_known_flags(c, ap, data, print));
}
