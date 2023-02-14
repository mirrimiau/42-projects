/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:30:34 by altikka           #+#    #+#             */
/*   Updated: 2022/12/08 10:02:35 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "optab.h"
# include "options.h"
# include "source.h"
# include "sh.h"
# include "parse.h"
# include "symtypes.h"
# include "label.h"
# include "lex.h"

int			valid_file(int argc, char *filename);
void		panic(const char *msg);
void		parse(t_sh *d, t_flag *f, char *filename);
void		assemble(t_sh *d, char *filename);
void		free_data(t_sh *d);

/*
** Utility functions for the assembly stage
*/

char		*create_filename(char *src);
void		write_file(t_sh *d, const int fd);
void		write_header(t_sh *d, const int fd);
u_int32_t	uint_to_bigendian(u_int32_t nbr);
u_int16_t	ushort_to_bigendian(u_int16_t nbr);
void		write_bytecode(t_sh *d, const int fd);

/*
** Functions for debugging
*/

void		debug_lex(t_token *t, t_src *s, size_t tnum);
void		debug_statement(t_sh *d);

#endif
