/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:07:22 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/08 09:33:33 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMTYPES_H
# define SYMTYPES_H

typedef enum e_symtypes
{
	la_unknown,
	la_eof,
	la_eol,
	la_label,
	la_op,
	la_comm,
	la_champname,
	la_champcomm,
	la_reg,
	la_dir,
	la_ind,
	la_arglabel,
	la_comma
}	t_symtypes;

static const char	*g_symstrs[13] = {
	"UNKNOWN",
	"END OF FILE",
	"END OF LINE",
	"LABEL",
	"OPERATION",
	"COMMENT",
	"CHAMPION'S NAME",
	"CHAMPION'S COMMENT",
	"REGISTER",
	"DIRECT",
	"INDIRECT",
	"LABEL AS ARGUMENT",
	"COMMA"
};

typedef struct s_token
{
	t_symtypes		symbol;
	t_vec			content;
}					t_token;

#endif
