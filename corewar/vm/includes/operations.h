/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:32 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/08 12:46:33 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "corewar.h"

/* Operation macros */
# define OP_COUNT 16

void	op_live(t_info *info, t_car *car);
void	op_ld(t_info *info, t_car *car);
void	op_st(t_info *info, t_car *car);
void	op_add(t_info *info, t_car *car);
void	op_sub(t_info *info, t_car *car);
void	op_and(t_info *info, t_car *car);
void	op_or(t_info *info, t_car *car);
void	op_xor(t_info *info, t_car *car);
void	op_zjmp(t_info *info, t_car *car);
void	op_ldi(t_info *info, t_car *car);
void	op_sti(t_info *info, t_car *car);
void	op_fork(t_info *info, t_car *car);
void	op_lld(t_info *info, t_car *car);
void	op_lldi(t_info *info, t_car *car);
void	op_lfork(t_info *info, t_car *car);
void	op_aff(t_info *info, t_car *car);

typedef void				(*t_operations)(t_info *, t_car *);

static const t_operations	g_op_jump_table[OP_COUNT + 1] = {
	NULL,
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_zjmp,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff
};

void	print_live(t_car *car, unsigned int arg);
void	print_ld(t_car *car, unsigned int args[]);
void	print_st(t_car *car, int args[]);
void	print_add(t_car *car, unsigned int args[]);
void	print_sub(t_car *car, unsigned int args[]);
void	print_and(t_car *car, unsigned int args[]);
void	print_or(t_car *car, unsigned int args[]);
void	print_xor(t_car *car, unsigned int args[]);
void	print_zjmp(t_car *car, unsigned int arg, bool success);
void	print_ldi(t_car *car, int args[]);
void	print_sti(t_car *car, int args[]);
void	print_fork(t_car *car, unsigned int arg);
void	print_lld(t_car *car, unsigned int args[]);
void	print_lldi(t_car *car, int args[]);
void	print_lfork(t_car *car, unsigned int arg);
void	print_aff(t_car *car, unsigned int arg);

#endif
