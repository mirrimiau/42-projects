/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:15 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 14:01:28 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse(t_sh *d, t_flag *f, char *filename)
{
	t_src	s;

	init_handler(d);
	init_source(&s);
	read_source(&s, filename);
	lex(d, f, &s);
	free_source(&s);
}
