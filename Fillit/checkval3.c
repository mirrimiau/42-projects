/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkval3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:30:24 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/18 18:30:29 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_t1(char *str, char *content)
{
	if (ft_strequ(str, "###..#..........")
		|| ft_strequ(str, ".###..#.........")
		|| ft_strequ(str, "....###..#......")
		|| ft_strequ(str, ".....###..#.....")
		|| ft_strequ(str, "........###..#..")
		|| ft_strequ(str, ".........###..#."))
	{
		ft_strcpy(content, "###..#..........");
		return (1);
	}
	if (ft_strequ(str, ".#..##...#......")
		|| ft_strequ(str, "..#..##...#.....")
		|| ft_strequ(str, "...#..##...#....")
		|| ft_strequ(str, ".....#..##...#..")
		|| ft_strequ(str, "......#..##...#.")
		|| ft_strequ(str, ".......#..##...#"))
	{
		ft_strcpy(content, ".#..##...#......");
		return (1);
	}
	return (0);
}

int	check_t2(char *str, char *content)
{
	if (ft_strequ(str, ".#..###.........")
		|| ft_strequ(str, "..#..###........")
		|| ft_strequ(str, ".....#..###.....")
		|| ft_strequ(str, "......#..###....")
		|| ft_strequ(str, ".........#..###.")
		|| ft_strequ(str, "..........#..###"))
	{
		ft_strcpy(content, ".#..###.........");
		return (1);
	}
	if (ft_strequ(str, "#...##..#.......")
		|| ft_strequ(str, ".#...##..#......")
		|| ft_strequ(str, "..#...##..#.....")
		|| ft_strequ(str, "....#...##..#...")
		|| ft_strequ(str, ".....#...##..#..")
		|| ft_strequ(str, "......#...##..#."))
	{
		ft_strcpy(content, "#...##..#.......");
		return (1);
	}
	return (0);
}
