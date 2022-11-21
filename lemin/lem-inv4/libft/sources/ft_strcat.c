/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:51 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/18 15:37:34 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *source)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (destination[i])
		i++;
	while (source[j])
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return (destination);
}
