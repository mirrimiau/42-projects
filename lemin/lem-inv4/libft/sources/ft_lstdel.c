/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:41:25 by mapostol          #+#    #+#             */
/*   Updated: 2021/11/19 15:41:46 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*next;

	if (!del || !*alst)
		return ;
	link = *alst;
	while (link)
	{
		next = link->next;
		del(link->content, link->content_size);
		free(link);
		link = next;
	}
	*alst = NULL;
}
