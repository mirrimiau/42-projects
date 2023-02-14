/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkval2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:28:39 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/18 18:28:42 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_l1(char *str, char *content)
{
	if (ft_strequ(str, "#...#...##......")
		|| ft_strequ(str, ".#...#...##.....")
		|| ft_strequ(str, "..#...#...##....")
		|| ft_strequ(str, "....#...#...##..")
		|| ft_strequ(str, ".....#...#...##.")
		|| ft_strequ(str, "......#...#...##"))
	{
		ft_strcpy(content, "#...#...##......");
		return (1);
	}
	if (ft_strequ(str, "###.#...........")
		|| ft_strequ(str, ".###.#..........")
		|| ft_strequ(str, "....###.#.......")
		|| ft_strequ(str, ".....###.#......")
		|| ft_strequ(str, "........###.#...")
		|| ft_strequ(str, ".........###.#.."))
	{
		ft_strcpy(content, "###.#...........");
		return (1);
	}
	return (0);
}

int	check_l2(char *str, char *content)
{
	if (ft_strequ(str, "##...#...#......")
		|| ft_strequ(str, ".##...#...#.....")
		|| ft_strequ(str, "..##...#...#....")
		|| ft_strequ(str, "....##...#...#..")
		|| ft_strequ(str, ".....##...#...#.")
		|| ft_strequ(str, "......##...#...#"))
	{
		ft_strcpy(content, "##...#...#......");
		return (1);
	}
	if (ft_strequ(str, "..#.###.........")
		|| ft_strequ(str, "...#.###........")
		|| ft_strequ(str, "......#.###.....")
		|| ft_strequ(str, ".......#.###....")
		|| ft_strequ(str, "..........#.###.")
		|| ft_strequ(str, "...........#.###"))
	{
		ft_strcpy(content, "..#.###.........");
		return (1);
	}
	return (0);
}

int	check_s(char *str, char *content)
{
	if (ft_strequ(str, "#...##...#......")
		|| ft_strequ(str, ".#...##...#.....")
		|| ft_strequ(str, "..#...##...#....")
		|| ft_strequ(str, "....#...##...#..")
		|| ft_strequ(str, ".....#...##...#.")
		|| ft_strequ(str, "......#...##...#"))
	{
		ft_strcpy(content, "#...##...#......");
		return (1);
	}
	if (ft_strequ(str, ".##.##..........")
		|| ft_strequ(str, "..##.##.........")
		|| ft_strequ(str, ".....##.##......")
		|| ft_strequ(str, "......##.##.....")
		|| ft_strequ(str, ".........##.##..")
		|| ft_strequ(str, "..........##.##."))
	{
		ft_strcpy(content, ".##.##..........");
		return (1);
	}
	return (0);
}

int	check_z(char *str, char *content)
{
	if (ft_strequ(str, ".#..##..#.......")
		|| ft_strequ(str, "..#..##..#......")
		|| ft_strequ(str, "...#..##..#.....")
		|| ft_strequ(str, ".....#..##..#...")
		|| ft_strequ(str, "......#..##..#..")
		|| ft_strequ(str, ".......#..##..#."))
	{
		ft_strcpy(content, ".#..##..#.......");
		return (1);
	}
	if (ft_strequ(str, "##...##.........")
		|| ft_strequ(str, ".##...##........")
		|| ft_strequ(str, "....##...##.....")
		|| ft_strequ(str, ".....##...##....")
		|| ft_strequ(str, "........##...##.")
		|| ft_strequ(str, ".........##...##"))
	{
		ft_strcpy(content, "##...##.........");
		return (1);
	}
	return (0);
}
