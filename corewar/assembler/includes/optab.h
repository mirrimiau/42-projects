/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optab.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:13 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/28 11:37:35 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTAB_H
# define OPTAB_H

# define OPTAB_SIZE 16

typedef struct s_op
{
	u_int8_t	op_code;
	char		*name;
	int			argc;
	t_arg_type	args[3];
	bool		acb;
	u_int8_t	size;
}				t_op;

static const t_op	g_optab[OPTAB_SIZE] = {
{1, "live", 1, {T_DIR}, false, 4},
{2, "ld", 2, {T_DIR | T_IND, T_REG}, true, 4},
{3, "st", 2, {T_REG, T_REG | T_IND}, true, 4},
{4, "add", 3, {T_REG, T_REG, T_REG}, true, 4},
{5, "sub", 3, {T_REG, T_REG, T_REG}, true, 4},
{6, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, true, 4},
{7, "or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, true, 4},
{8, "xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, true, 4},
{9, "zjmp", 1, {T_DIR}, false, 2},
{10, "ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, true, 2},
{11, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR}, true, 2},
{12, "fork", 1, {T_DIR}, false, 2},
{13, "lld", 2, {T_DIR | T_IND, T_REG}, true, 4},
{14, "lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, true, 2},
{15, "lfork", 1, {T_DIR}, false, 2},
{16, "aff", 1, {T_REG}, true, 4}
};

#endif
