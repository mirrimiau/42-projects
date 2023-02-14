/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:49:05 by altikka           #+#    #+#             */
/*   Updated: 2022/12/11 15:24:24 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

typedef struct s_statement
{
	t_op		op;
	u_int8_t	acb;
	int			args[3];
	u_int8_t	arg_type[3];
	int			cur_arg;
	int			sep;
	bool		is_dir;
	bool		is_valid;
	u_int32_t	loc;
}				t_statement;

typedef struct s_sh
{
	t_header	header;
	t_vec		code;
	t_hashmap	ops;
	bool		op_in_line;
	bool		eof_is_valid;
	char		*filename;
	u_int32_t	byte;
}				t_sh;

#endif
