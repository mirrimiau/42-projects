/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:25:47 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/10 18:46:33 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;
	size_t			i;

	i = 0;
	area = (unsigned char *) malloc(sizeof(unsigned char) * size);
	if (area == NULL)
		return (NULL);
	while (i < size)
	{
		*(area + i) = '\0';
		i++;
	}
	return (area);
}
