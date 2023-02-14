/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:54:06 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/16 17:20:23 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *) ft_memalloc(sizeof(t_list));
	if (fresh == NULL)
		return (NULL);
	if (content == NULL)
		content_size = 0;
	fresh->content = (void *) content;
	fresh->content_size = content_size;
	fresh->next = NULL;
	return (fresh);
}
