/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:43:25 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/18 18:05:29 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *) b;
	while (len > 0)
	{
		*a = (unsigned char) c;
		a++;
		len--;
	}
	return (b);
}
