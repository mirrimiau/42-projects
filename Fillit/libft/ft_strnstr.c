/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:52:28 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/15 13:22:34 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	j = 0;
	while (haystack[j] && len != 0)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (int)len - i != 0)
		{
			if (needle[i + 1] == '\0')
				return ((char *) haystack + j);
			i++;
		}
		j++;
		len--;
	}
	return (NULL);
}
