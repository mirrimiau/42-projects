/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:53:40 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 16:55:22 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (!*needle)
		return ((char *) haystack);
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (ft_tolower(haystack[j + i]) == ft_tolower(needle[i]))
		{
			if (needle[i + 1] == '\0')
				return ((char *) haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
