/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:33:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/10 17:19:29 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

void	init_lex(t_token *t, t_labtab *lt);
void	panic_lex(const char *msg, t_token *t, size_t row, size_t col);
void	panic_invalidarg(const char *msg, t_src *s, t_statement *stmt);
void	lex_tokenization(t_sh *d, t_src *s, t_token *t, t_labtab *lt);
void	lex_endof(t_sh *d, t_src *s, t_token *t);
void	lex_comment(t_src *s, t_token *t);
void	lex_header(t_sh *d, t_src *s, t_token *t);
void	lex_command(t_sh *d, t_src *s, t_token *t, t_labtab *lt);
void	lex_argument(t_sh *d, t_src *s, t_token *t, t_labtab *lt);
void	lex_label(t_sh *d, t_src *s, t_labtab *lt, char *key);
void	lex_comma(t_sh *d, t_src *s, t_token *t);
void	validate_separators(t_statement *stmt, int row, int col);
void	label_fill(t_sh *d, t_vec *entries, t_hash *entry, bool is_arg);
void	check_labels(t_labtab *lt);

bool	is_label_chars(int c);
bool	is_label(t_src *s);
bool	is_register(t_src *s);
bool	is_valid_header(t_src *s);
void	calc_arg_size(t_sh *d, t_statement *stmt, const char c);
int		validate_arg(t_statement *s, int arg);
void	reset_token(t_token *t);

#endif
