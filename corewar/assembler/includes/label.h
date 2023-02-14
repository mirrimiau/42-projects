/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:12:18 by altikka           #+#    #+#             */
/*   Updated: 2022/12/01 12:18:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

typedef struct s_undeflab
{
	u_int32_t			stmt;
	u_int8_t			arg;
	u_int32_t			loc;
	bool				is_dir;
	struct s_undeflab	*next;
}						t_undeflab;

typedef struct s_label
{
	char				*name;
	bool				declared;
	bool				is_dir;
	size_t				pos[2];
	struct s_undeflab	*head;
}						t_label;

typedef struct s_labtab
{
	t_hashmap	labels;
	t_vec		entries;
}				t_labtab;

void	free_labtab(t_labtab *lt);

#endif
