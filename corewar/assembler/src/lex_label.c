/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:02 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 16:02:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	label_add(t_sh *d, t_label *lab)
{
	t_statement	*temp_stmt;
	t_undeflab	*temp_node;
	t_undeflab	*node;

	temp_stmt = ft_vecget(&d->code, d->code.len - 1);
	node = (t_undeflab *)ft_memalloc(sizeof(t_undeflab));
	if (!node)
		panic("Error: Malloc error while adding a label node.");
	node->stmt = d->code.len - 1;
	node->arg = temp_stmt->cur_arg;
	node->loc = d->byte;
	node->is_dir = lab->is_dir;
	node->next = NULL;
	temp_node = lab->head;
	while (temp_node->next)
		temp_node = temp_node->next;
	temp_node->next = node;
}

static void	label_new(t_sh *d, t_src *s, t_label *lab)
{
	t_statement	*temp_stmt;
	t_undeflab	*node;

	temp_stmt = ft_vecget(&d->code, d->code.len - 1);
	node = (t_undeflab *)ft_memalloc(sizeof(t_undeflab));
	if (!node)
		panic("Error: Malloc error while creating the first label node.");
	node->stmt = d->code.len - 1;
	node->arg = temp_stmt->cur_arg;
	node->loc = d->byte;
	node->is_dir = lab->is_dir;
	node->next = NULL;
	lab->head = node;
	lab->pos[0] = s->row;
	lab->pos[1] = s->col;
}

static void	label_init(t_sh *d, t_label *l, char *key, bool is_first)
{
	t_statement	*stmt;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	l->name = key;
	l->declared = false;
	l->is_dir = stmt->is_dir;
	ft_bzero(&l->pos, sizeof(size_t) * 2);
	if (is_first)
		l->head = NULL;
}

static char	*get_label(t_src *s)
{
	char	*key;
	char	*p;

	p = (char *)&s->buf.data[s->index];
	if (*p == DIRECT_CHAR && *s->next == LABEL_CHAR)
	{
		p += 2;
		source_adjust(s, 2, false);
	}
	else
	{
		p++;
		source_adjust(s, 1, false);
	}
	while (is_label_chars(*p))
		p++;
	key = ft_strsub((char *)&s->buf.data[s->index], 0,
			p - (char *)&s->buf.data[s->index]);
	source_adjust(s, ft_strlen(key), false);
	return (key);
}

void	lex_label(t_sh *d, t_src *s, t_labtab *lt, char *key)
{
	t_hash	*entry;
	t_label	label;

	key = get_label(s);
	entry = hash_get(&lt->labels, key);
	if (!entry)
	{
		label_init(d, &label, key, true);
		label_new(d, s, &label);
		ft_vecpush(&lt->entries, &label);
		hash_insert(&lt->labels, key, ((int)lt->entries.len * -1));
	}
	else if (entry)
	{
		if (entry->value < 0)
		{
			label_init(d, ft_vecget(&lt->entries, ft_abs(entry->value + 1)),
				key, false);
			label_add(d, ft_vecget(&lt->entries, ft_abs(entry->value + 1)));
		}
		else
			label_fill(d, &lt->entries, entry, true);
		ft_strdel(&key);
	}
}
