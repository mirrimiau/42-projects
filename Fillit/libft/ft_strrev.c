/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:39:20 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 17:40:11 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	char	temp;
	int		i;
	int		j;

	if (!s)
		return ;
	i = 0;
	j = (int)(ft_strlen(s) - 1);
	while (s[i] && (i < j))
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	s[ft_strlen(s) + 1] = '\0';
}
