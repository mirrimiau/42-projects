/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:52:34 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/12 12:30:47 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	size;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size == 0)
		return (NULL);
	map = (char *) malloc(size + 1);
	if (map == NULL)
		return (NULL);
	ft_strcpy(map, s);
	while (map[i])
	{
		map[i] = (*f)(map[i]);
		i++;
	}	
	return (map);
}
