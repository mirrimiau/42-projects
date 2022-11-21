/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:01:22 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/15 12:43:06 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
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
		{
			if (ft_strrchr(str + 1, c) == NULL)
				return ((char *) str);
			else
				ft_strrchr(str + 1, c);
		}
		str++;
	}
	return (NULL);
}
