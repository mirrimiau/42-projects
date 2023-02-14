/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:04:21 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/26 16:04:23 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* 
Priority : %{text attributes}[flags][width][.precision][length]specifier

Text attributes: Bold (1), Underline (2), blink (3), dark color (RGB), 
	light color (rgb), b(a)ckground + color, O(ff).
		color = (rgbw, cmyk)

Flags: - + space # 0 in any order
Width: number and *
Precision: .number and .*
Length: h, hh, l, ll, L
Specifier: diouxX, csp, f, %% 
*/
void	set_data_to_false(t_option *data)
{
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->zero = 0;
	data->hash = 0;
	data->precision = -1;
	data->h = 0;
	data->hh = 0;
	data->l = 0;
	data->ll = 0;
	data->cap_l = 0;
	data->cap_x = 0;
	data->precision_len = 0;
	data->width = -1;
	data->width_len = 0;
	data->negative = 0;
	data->positive = 0;
	data->hash_len = 0;
	data->dollar = 0;
	data->asterisk = 0;
	data->attribute = 0;
}

void	refresh_variables(t_printingblock *prints, t_option *data)
{
	prints->i += 1 + data->l + data->ll + data->h + data->hh + data->cap_l
		+ data->precision_len + data->zero + data->minus + data->plus
		+ data->hash + data->space + data->width_len + data->dollar
		+ data->asterisk + data->attribute;
	resolve_width(prints->data, prints->print);
	ft_strcat(prints->cat, prints->print);
	ft_bzero(prints->print, 10000);
}

void	construct_print(t_printingblock *prints, const char *format)
{
	set_data_to_false(prints->data);
	if (format[prints->i] == '%')
	{
		prints->i++;
		if (!check_known_attributes((char *)(format + prints->i),
			prints->ap, prints->data, prints->print))
		{
			if (format[prints->i] && format[prints->i] != ' '
				&& format[prints->i] != '+' && format[prints->i] != '-'
				&& format[prints->i] != '#' && format[prints->i] != '.'
				&& !ft_isdigit(format[prints->i]))
				ft_strncat(prints->print, &format[prints->i], 1);
			else
				prints->i--;
		}
	}
	else
	{
		ft_strncat(prints->print, &format[prints->i], 1);
	}
	refresh_variables(prints, prints->data);
}

int	ft_printf(const char *format, ...)
{
	t_printingblock	*prints;

	prints = (t_printingblock *) malloc(sizeof(t_printingblock));
	prints->data = (t_option *) malloc(sizeof(t_option));
	if (prints == NULL || prints->data == NULL)
		exit(0);
	ft_bzero(prints->print, 10000);
	ft_bzero(prints->cat, 10000);
	va_start(prints->ap, format);
	prints->i = 0;
	prints->data->null_char = 0;
	while (format[prints->i])
		construct_print(prints, format);
	write(1, prints->cat, ft_strlen(prints->cat));
	free (prints->data);
	free (prints);
	va_end(prints->ap);
	return (ft_strlen(prints->cat) + prints->data->null_char);
}
