/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:53:27 by altikka           #+#    #+#             */
/*   Updated: 2022/12/05 16:54:39 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	label_set_arg(t_sh *d, t_hash *entry)
{
	t_statement	*temp_stmt;

	temp_stmt = ft_vecget(&d->code, d->code.len - 1);
	temp_stmt->args[temp_stmt->cur_arg] = entry->value - temp_stmt->loc;
}

void	label_fill(t_sh *d, t_vec *entries, t_hash *entry, bool is_arg)
{
	t_statement	*temp_stmt;
	t_undeflab	*temp_undeflab;
	t_label		*label;

	if (entry->value > -1)
	{
		if (is_arg == true)
			label_set_arg(d, entry);
		return ;
	}
	label = ft_vecget(entries, ft_abs(entry->value + 1));
	label->declared = true;
	temp_undeflab = label->head;
	while (temp_undeflab)
	{
		temp_stmt = ft_vecget(&d->code, temp_undeflab->stmt);
		temp_stmt->args[temp_undeflab->arg] = d->byte - temp_stmt->loc;
		temp_undeflab = temp_undeflab->next;
	}
	entry->value = d->byte;
}
