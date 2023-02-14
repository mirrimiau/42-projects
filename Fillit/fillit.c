/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:28:58 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/10 13:29:04 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_last_tetrimino(char solved[25][25],
	t_map tetrimino, int *x, int *y)
{
	int	count;

	backtrack_to_map(solved, tetrimino.dim, x, y);
	count = 0;
	while (solved[*y][*x] && count < 4)
	{
		if (solved[*y][*x] == tetrimino.c)
		{
			solved[*y][*x] = '.';
			count++;
		}
		(*x)--;
		if (*x < 0)
		{
			*x = tetrimino.dim - 1;
			(*y)--;
		}
	}
	raise_x(x, y, tetrimino.dim);
	raise_x(x, y, tetrimino.dim);
}
/* 
1. Place blocks from the tetrimino to the global coordinates.
2. Keep count on how many got placed.
 */

int	blocks_placed(int i[9], t_map tetriminos[26 + 1],
	int dim, char solved[25][25])
{
	while (tetriminos[i[0]].cords[i[2]][i[1]] && i[8] < 4)
	{
		if (tetriminos[i[0]].cords[i[2]][(i[1])]
			&& tetriminos[i[0]].cords[i[2]][(i[1])] != '.'
			&& solved[i[4]][i[3]] != '.')
			break ;
		if (tetriminos[i[0]].cords[i[2]][(i[1])] != '.')
		{
			i[8]++;
			solved[i[4]][i[3]] = tetriminos[i[0]].c;
		}
		raise_x(&i[3], &i[4], dim);
		raise_x(&i[1], &i[2], 4);
		if (i[1] == 0)
			while (i[3] != 0)
				raise_x(&i[3], &i[4], dim);
		if (i[3] == 0)
		{
			while (i[1] != 0)
				raise_x(&i[1], &i[2], 4);
			i[3] = i[6] - i[5];
		}
	}
	return (i[8]);
}

/* 
1. Set local origin to correspond the place in global coordinates
2. Try to fit the tetrimino, and keep count on how many blocks got placed
3. If all 4, reset the global coordinates to (0,0) 
	and start over with the next tetrimino
4. If less than 4, clear the placed blocks of the tetrimino 
	and start over from the next vacant spot. 
*/
int	fit_tetrimino(int i[9], t_map tetriminos[26 + 1],
	int dim, char solved[25][25])
{
	i[1] = i[5];
	i[2] = 0;
	i[3] = i[6];
	i[4] = i[7];
	i[8] = blocks_placed(i, tetriminos, dim, solved);
	if (i[8] < 4)
	{
		tetriminos[i[0]].dim = dim;
		clear_last_tetrimino(solved, tetriminos[i[0]], &i[3], &i[4]);
		raise_x(&i[6], &i[7], dim);
		return (0);
	}
	return (1);
}

/* 
1. Find vacant coord.
2. If no vacant coords, backtrack.
3. If can't backtrack, dim + 1 and solve again.
 */
int	find_next_valid_coord(t_map tetriminos[26 + 1], char solved[25][25],
	int dim, int i[9])
{
	while (tetriminos[i[0]].cords[i[2]][i[5]] == '.')
		i[5]++;
	while (solved[i[7]][i[6]])
	{
		if (solved[i[7]][i[6]] == '.')
		{
			if (i[0] == 0 || check_valid_spot(solved, tetriminos[i[0]], i))
				break ;
		}
		raise_x(&i[6], &i[7], dim);
	}
	if (!solved[i[7]][i[6]])
	{
		i[0]--;
		if (i[0] < 0)
			return (solve_tetriminos(tetriminos, solved, dim + 1));
		tetriminos[i[0]].dim = dim;
		clear_last_tetrimino(solved, tetriminos[i[0]], &i[6], &i[7]);
		return (0);
	}
	return (1);
}

/* 	
1. Set all integer variables to 0
2. Create a dim * dim empty map filled with '.'
3. Start from tetrimino A and check for valid coordinates to insert it
4. Insert it.
5. Switch to the next tetrimino, repeat from 3
6. If one of the tetriminos doesn't fit, backtrack the last one and
	repeat from 3
7. If no longer able to backtrack, start the function from the beginning
	with an empty map of dim + 1 dimensions.

	tetrimino array index				0
	tetrimino x							1
	tetrimino y							2
	temporary change of global coord x	3
	temporary change of global coord y	4
	temporary change of tetrimino x		5
	global coord x						6
	global coord y						7
	block count							8 
*/
int	solve_tetriminos(t_map tetriminos[26 + 1], char solved[25][25], int dim)
{
	int	i[9];

	ft_bzero(i, sizeof(i));
	empty_map(solved, dim);
	while (*(tetriminos[i[0]].shape))
	{
		i[5] = 0;
		i[1] = 0;
		i[2] = 0;
		i[8] = 0;
		if (!find_next_valid_coord(tetriminos, solved, dim, i))
			continue ;
		if (fit_tetrimino(i, tetriminos, dim, solved))
		{
			i[6] = 0;
			i[7] = 0;
			i[0]++;
		}
	}
	return (0);
}
