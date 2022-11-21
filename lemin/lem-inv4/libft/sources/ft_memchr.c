/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:47:24 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/18 18:06:45 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	needle;
	unsigned char	*array;
	size_t			i;

	i = 0;
	needle = (unsigned char) c;
	array = (unsigned char *) s;
	while (i < n)
	{
		if (array[i] == needle)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
