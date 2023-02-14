/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:57:20 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/07 12:57:21 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(char a[BUF][12])
{
	char	c[12];
	int		i;

	if (a[0][0])
	{
		i = 0;
		ft_strcpy(c, a[0]);
		while (a[i + 1][0])
		{
			ft_strcpy(a[i], a[i + 1]);
			i++;
		}
		ft_strcpy(a[i], c);
	}
	return (1);
}

int	reverse_rotate(char a[BUF][12])
{
	int		i;
	char	c[12];

	i = 0;
	while (a[i + 1][0])
		i++;
	ft_strcpy(c, a[i]);
	while (i != 0)
	{
		ft_strcpy(a[i], a[i - 1]);
		i--;
	}
	ft_strcpy(a[0], c);
	return (1);
}

int	put(char dest[BUF][12], char src[BUF][12])
{
	int	i;

	i = 0;
	if (src[0][0])
	{
		while (dest[i][0])
			i++;
		while (i != 0)
		{
			ft_strcpy(dest[i], dest[i - 1]);
			i--;
		}
		ft_strcpy(dest[0], src[0]);
		while (src[i + 1][0])
		{
			ft_strcpy(src[i], src[i + 1]);
			i++;
		}
		ft_bzero(src[i], 10);
	}
	return (1);
}

int	swap(char a[BUF][12])
{
	int		c;
	char	*temp;

	if (a[0][0] && a[1][0])
	{
		c = ft_atoi(a[0]);
		ft_strcpy(a[0], a[1]);
		temp = ft_itoa(c);
		ft_strcpy(a[1], temp);
		free (temp);
	}
	return (1);
}
