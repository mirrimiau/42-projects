/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:07:15 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 14:39:53 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splitcount(const char *s, char c)
{
	size_t	ret;
	size_t	i;

	if (!s[0])
		return (0);
	ret = 0;
	i = 0;
	if (s[i] && s[i] != c)
		ret++;
	i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
		{
			ret++;
			i++;
		}
		else
			i++;
	}
	return (ret);
}

static void	nextsplit(char **str, size_t *len, char c)
{
	size_t	i;

	*str += *len;
	*len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_strsplit(char const *s, char c)
{	
	size_t	len;
	size_t	splits;
	size_t	i;
	char	*str;
	char	**pntr;

	if (!s)
		return (NULL);
	splits = splitcount(s, c);
	pntr = (char **)ft_memalloc(sizeof(char *) * (splits + 1));
	if (!pntr)
		return (NULL);
	i = 0;
	str = (char *)s;
	len = 0;
	while (i < splits)
	{
		nextsplit(&str, &len, c);
		pntr[i] = ft_strnew(len + 1);
		ft_memcpy(pntr[i++], str, len);
	}
	pntr[i] = NULL;
	return (pntr);
}
