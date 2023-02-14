/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:01:14 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 14:06:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define ASM_USAGE "\nusage: ./asm [-dh] <file.s>\n\
 options:\n\
 \t\e[1m-d\e[m\tdebug mode - displays tokenization and operations\n\
 \t\e[1m-h\e[m\thelp\n"

# define ASM_FLAGS "dh"

typedef enum e_flag
{
	NONE,
	DEBUG
}	t_flag;

int		init_options(t_flag *flag, int argc, char **argv);

#endif
