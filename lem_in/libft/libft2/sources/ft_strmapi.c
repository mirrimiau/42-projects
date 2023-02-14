/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:17:39 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/12 11:28:19 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	size_t			size;
	unsigned int	i;

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
		map[i] = (*f)(i, map[i]);
		i++;
	}	
	return (map);
}
