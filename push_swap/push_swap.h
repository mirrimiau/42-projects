/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:02:03 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/16 17:02:05 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define BUF		10000
# include "libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_link
{
	char			content[12];
	int				c;
	int				placement;
	int				total;
	int				block;
	int				block_total;
	struct s_link	*next;
	struct s_link	*previous;
}	t_link;

typedef struct s_block_minmax
{
	char	largest[12];
	int		largest_i;
	char	smallest[12];
	int		smallest_i;
	int		i;
	int		top;
	int		bottom;
	t_link	*temp;
}	t_block_minmax;

typedef struct s_writing_var
{
	int		i;
	int		j;
	char	*temp;
}	t_writing_var;

int		swap(char a[BUF][12]);
int		put(char dest[BUF][12], char src[BUF][12]);
int		rotate(char a[BUF][12]);
int		reverse_rotate(char a[BUF][12]);
void	smartput_from_b_to_a(char a[BUF][12], char b[BUF][12], t_link *sorted);
void	smart_orientate_a(char a[BUF][12], char *first, int total);
void	smart_orientate_b(char a[BUF][12], char *first, int total);
int		resolve_input(char *input, char a[BUF][12], char b[BUF][12]);
int		commands(char a[BUF][12], char b[BUF][12], int debugmode);
int		write_a(char a[BUF][12], int argc, char **argv);
void	check_ok(char a[BUF][12], char b);
int		write_a_single_arg(char a[BUF][12], int *argc, char *s);
void	solve_twostack(char a[BUF][12]);
void	solve_threestack(char a[BUF][12]);
void	solve_fivestack(char a[BUF][12], char b[BUF][12]);
void	solve_largestack(char a[BUF][12], char b[BUF][12]);
t_link	*create_sorted_link(char a[BUF][12]);
void	loop_link_ends(t_link *ini);
int		check_if_in_stack(char a[BUF][12], char *needle);
int		stack_len(char a[BUF][12]);
int		block_count(int total);
void	put_block(char dest[BUF][12], char src[BUF][12],
			int block, t_link *sorted);
void	put_all(char dest[BUF][12], char src[BUF][12]);
void	sorted_block_b_to_a(char a[BUF][12], char b[BUF][12]);
t_link	*get_link(char *content, t_link *sorted);
void	free_links(t_link *sorted);
void	set_next_link_values(t_link *newlink);
void	printlinks(t_link *ini);
void	resolve_input_r(int *i, char input[BUF],
			char a[BUF][12], char b[BUF][12]);
int		test_bounds(char *str);
void	print_db_data(char a[BUF][12], char b[BUF][12], t_link *sorted);

#endif
