/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:23:43 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 15:18:48 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	while (s[i] && *s)
		i++;
	if (i == 0)
		return (ft_strdup("\0"));
	while (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
		i--;
	fresh = (char *) malloc(sizeof(char) * (size_t)i + 1);
	if (fresh == NULL)
		return (NULL);
	ft_strcpy(fresh, s);
	fresh[i] = '\0';
	return (fresh);
}
