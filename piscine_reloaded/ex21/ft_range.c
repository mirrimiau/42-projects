/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:48:42 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/01 12:23:43 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*list;
	int	i;

	if (min >= max)
		return (NULL);
	list = (int *) malloc(4 * (max - min));
	i = 0;
	while (min < max)
	{
		list[i] = min;
		i++;
		min++;
	}
	return (list);
}
