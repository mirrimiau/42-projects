/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:04:28 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/26 16:04:28 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_option
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hash;
	int	width;
	int	precision;
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	cap_l;
	int	cap_x;
	int	width_len;
	int	precision_len;
	int	hash_len;
	int	negative;
	int	positive;
	int	null_char;
	int	dollar;
	int	asterisk;
	int	attribute;
	int	base;
}	t_option;

typedef struct s_doubledata
{
	int			len;
	long double	dpart;
	int			copy;
	char		*f_itoa;
}	t_doubledata;

typedef struct s_printingblock
{
	va_list		ap;
	int			i;
	t_option	*data;
	char		print[10000];
	char		cat[10000];
}	t_printingblock;

int			ft_printf(const char *restrict format, ...);
size_t		uint_len_base_x(unsigned long n, const int x);
void		uitoa_base_x(unsigned long n, const int x, t_option *data,
				char fresh[100]);
void		long_double_to_str(const long double f, int precision,
				int hash, char ret[100]);
void		resolve_flags(long long n, t_option *data,
				int x, char print[10000]);
void		resolve_space(long long n, long double f,
				t_option *data, char print[10000]);
void		resolve_width(t_option *data, char print[10000]);
void		resolve_asterisk_dollarsign(char *c, va_list ap,
				t_option *data, int *i);
void		resolve_asterisk_nonzero(char *c, va_list ap, t_option *data,
				int *i);
void		resolve_hash(long long n, t_option *data, int x, char print[10000]);
int			basic_attributes(char **c);
int			rgbw_attributes(char **c);
int			cmyk_attributes(char **c);
int			cap_rgbw_attributes(char **c);
int			cap_cmyk_attributes(char **c);
int			check_known_attributes(char *c, va_list ap, t_option *data,
				char print[10000]);
int			check_known_flags(char *c, va_list ap, t_option *data,
				char print[10000]);
int			check_known_precision(char *c, va_list ap, t_option *data,
				char print[10000]);
int			check_known_width(char *c, va_list ap, t_option *data,
				char print[10000]);
int			check_known_length(char *c, va_list ap, t_option *data,
				char print[10000]);
int			check_known_specifiers(char c, va_list ap, t_option *data,
				char print[10000]);
int			check_asterisk_dollarsign_and_nonzero(char *c, va_list ap,
				t_option *data, int *i);
int			specifier_oux_base_x(va_list ap, t_option *data, int x,
				char print[10000]);
int			check_specifiers_dioux(char c, va_list ap,
				t_option *data, char print[10000]);
int			background_rgbw_attributes(char **c);
int			background_cmyk_attributes(char **c);
int			background_cap_rgbw_attributes(char **c);
int			background_cap_cmyk_attributes(char **c);
void		resolve_plus(long long n, t_option *data, char print[10000]);
void		resolve_hash(long long n, t_option *data, int x, char print[10000]);
void		resolve_flags(long long n, t_option *data, int x,
				char print[10000]);
void		resolve_space(long long n, long double f, t_option *data,
				char print[10000]);
void		resolve_specifier_s(va_list ap, t_option *data,	char print[10000]);

#endif