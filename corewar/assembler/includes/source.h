/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:15:33 by altikka           #+#    #+#             */
/*   Updated: 2022/12/09 10:57:22 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include <fcntl.h>

typedef struct s_src
{
	t_vec	buf;
	size_t	row;
	size_t	col;
	size_t	index;
	char	*next;
	size_t	name[2];
	size_t	comment[2];
}			t_src;

void	init_source(t_src *s);
void	read_source(t_src *s, const char *filename);
void	panic_source(int fd, const char *msg);
void	source_next(t_src *s);
void	source_adjust(t_src *s, int len, bool flag);
void	skip_whitespace(t_src *s);
void	free_source(t_src *s);

#endif
