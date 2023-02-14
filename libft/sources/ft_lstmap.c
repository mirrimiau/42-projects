/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:42:53 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 15:43:43 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*pointer;

	fresh = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!fresh)
		return (NULL);
	pointer = fresh;
	while (lst->next)
	{
		lst = lst->next;
		fresh->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!fresh->next)
			return (NULL);
		fresh = fresh->next;
	}
	return (pointer);
}
