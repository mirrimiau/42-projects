/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:00:34 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 14:01:53 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	init_handler(t_sh *d);
int		parse_header(t_sh *d, t_src *s);
void	lex(t_sh *d, t_flag *f, t_src *s);

#endif
