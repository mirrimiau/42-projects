/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:57:50 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/18 18:06:19 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	size_t				i;
	unsigned char		needle;

	needle = (unsigned char) c;
	cdest = (unsigned char *) dest;
	csrc = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		if (csrc[i] == needle)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
