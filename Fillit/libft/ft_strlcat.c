/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:44:31 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 15:08:38 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int		j;
	size_t	k;
	size_t	osize;

	if (n == 0)
		return (ft_strlen(src));
	osize = ft_strlen(dest);
	j = 0;
	k = 0;
	while (dest[k])
		k++;
	while (src[j] && k < n - 1)
	{
		dest[k] = src[j];
		j++;
		k++;
	}
	dest[k] = '\0';
	if (osize <= n)
		return (ft_strlen(src) + osize);
	else
		return (ft_strlen(src) + n);
}
