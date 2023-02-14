/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:53:56 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/16 15:28:05 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (!*needle)
		return ((char *) haystack);
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (haystack[j + i] == needle[i])
		{
			if (needle[i + 1] == '\0')
				return ((char *) haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
