/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:59:10 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/12 13:02:47 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fresh)
		return (NULL);
	i = 0;
	while (*s1)
	{
		fresh[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		fresh[i] = *s2;
		s2++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
