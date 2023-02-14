/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:03:46 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/01 15:42:32 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	int		i;

	count = 0;
	if (str[0] == '\0')
		return (count);
	i = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}
