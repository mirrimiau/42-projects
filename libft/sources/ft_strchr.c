/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:27 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/15 12:40:47 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	cchar;

	if (c < 0 || c > 255)
		return (NULL);
	cchar = (unsigned char)c;
	if (cchar == '\0')
	{
		while (*str)
			str++;
		return ((char *) str);
	}
	while (*str)
	{
		if (*str == cchar)
			return ((char *) str);
		str++;
	}
	return (NULL);
}
