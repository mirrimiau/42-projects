/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:40:07 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/18 18:06:33 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src > dest)
		ft_memcpy(dest, src, len);
	else if (src < dest)
	{
		len--;
		while (len + 1 > 0)
		{
			((char *)dest)[len] = ((char *)src)[len];
			len--;
		}
	}
	return (dest);
}
