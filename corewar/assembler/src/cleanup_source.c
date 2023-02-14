/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:16:26 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 16:07:45 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_source(t_src *s)
{
	ft_vecdel(&s->buf);
	s->next = NULL;
}

void	panic_source(int fd, const char *msg)
{
	ft_dprintf(2, "Error: %s\n", msg);
	close(fd);
	exit(EXIT_FAILURE);
}
