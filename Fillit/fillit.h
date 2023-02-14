/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:29:50 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/10 13:29:53 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	c;
	char	cords[5][5];
	char	shape[16 + 1];
	int		dim;
}	t_map;

int		check_validity(char *str, char *content);
int		check_square(char *str, char *content);
int		check_bar(char *str, char *content);
int		check_j1(char *str, char *content);
int		check_j2(char *str, char *content);
int		check_l1(char *str, char *content);
int		check_l2(char *str, char *content);
int		check_s(char *str, char *content);
int		check_z(char *str, char *content);
int		check_t1(char *str, char *content);
int		check_t2(char *str, char *content);
int		check_valid_spot(char solved[25][25], t_map tetrimino, int index[9]);
int		ft_out(char *reason);
int		getdim(t_map tetriminos[26 + 1]);
int		create_tetriminos(t_map tetriminos[26 + 1], char buf[1000]);
int		read_create_tetriminos(t_map tetriminos[26 + 1], int fd);
int		solve_tetriminos(t_map tetriminos[26 + 1], char solved[25][25],
			int dim);
int		read_create_tetriminos(t_map tetriminos[26 + 1], int fd);
void	raise_x(int *x, int *y, int dim);
void	print_solution(char solved[25][25]);
void	set_coordinates(t_map tetriminos[26 + 1]);
void	add_null_to_top(t_map tetrimino, int i[3]);
void	set_coordinates(t_map tetriminos[26 + 1]);
void	empty_map(char solved[25][25], int dim);
void	backtrack_to_map(char solved[25][25], int dim, int *x, int *y);

#endif