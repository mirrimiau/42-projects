/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:33:02 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/21 12:33:04 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define BUF		1024
# include "libft/libft.h"

typedef struct s_data
{
	char	map[BUF][BUF];
	char	piece[BUF][BUF];
	int		heatmap[BUF][BUF];
	char	xo_me;
	char	xo_opp;
	int		height;
	int		width;
	int		p_height;
	int		p_width;
	int		y;
	int		x;
	int		initialize;
	int		fd;
}	t_data;

/* 
parsing.c
Functions for info parsing from input.
*/
int		initiate_players(t_data *data);
void	parse_map(t_data *data);
void	parse_piece_dimensions(t_data *data);
void	parse_piece(t_data *data);
/* 
heatmap.c
Heatmap initiation, creation and verification
*/
int		calculate_heat(t_data *f);
int		heatmap_complete(t_data *data);
void	create_heatmap(t_data *data);
void	format_heatmap(t_data *data);
void	compare_orthogonal_heat(t_data *data, int *i, int *j, int min);
/* 
solving.c
Functions for finding allowed placements for a piece
*/
void	calculate_heat_row(t_data *data, int *i, int *j);
int		char_part_of_board(char c);
int		check_collisions(t_data *f);
void	resolve_row(t_data *f, int *heat, int *x_opt, int *y_opt);
int		place_piece(t_data *f);

#endif
