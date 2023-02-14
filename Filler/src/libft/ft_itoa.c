/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:38:41 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 15:25:28 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	countdigits(int i)
{
	int	digits;

	if (i == -2147483648)
		return (11);
	digits = 1;
	if (i < 0)
	{
		digits++;
		i = -i;
	}
	while (i >= 10)
	{
		digits++;
		i = i / 10;
	}
	return (digits);
}

static char	*construct(int n, char *a, int sign, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		a[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (sign == -1)
		a[0] = '-';
	return (a);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		sign;
	int		size;

	size = countdigits(n);
	a = (char *) malloc(sizeof(char) * (size_t) size + 1);
	if (a == NULL)
		return (NULL);
	a[size] = '\0';
	sign = 1;
	if (n == -2147483648)
	{
		ft_strcpy(a, "-2147483648");
		return (a);
	}
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	return (construct(n, a, sign, size));
}
