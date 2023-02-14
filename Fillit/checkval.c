/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:40:55 by mapostol          #+#    #+#             */
/*   Updated: 2022/01/11 17:40:57 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_validity(char *str, char *content)
{
	int	ret;

	ret = check_square(str, content);
	if (ret != 1)
		ret = check_bar(str, content);
	if (ret != 1)
		ret = check_j1(str, content);
	if (ret != 1)
		ret = check_j2(str, content);
	if (ret != 1)
		ret = check_l1(str, content);
	if (ret != 1)
		ret = check_l2(str, content);
	if (ret != 1)
		ret = check_s(str, content);
	if (ret != 1)
		ret = check_z(str, content);
	if (ret != 1)
		ret = check_t1(str, content);
	if (ret != 1)
		ret = check_t2(str, content);
	return (ret);
}

int	check_square(char *str, char *content)
{
	if (ft_strequ(str, "##..##..........")
		|| ft_strequ(str, ".##..##.........")
		|| ft_strequ(str, "..##..##........")
		|| ft_strequ(str, "....##..##......")
		|| ft_strequ(str, ".....##..##.....")
		|| ft_strequ(str, "......##..##....")
		|| ft_strequ(str, "........##..##..")
		|| ft_strequ(str, ".........##..##.")
		|| ft_strequ(str, "..........##..##"))
	{
		ft_strcpy(content, "##..##..........");
		return (1);
	}
	return (0);
}

int	check_bar(char *str, char *content)
{
	if (ft_strequ(str, "####............")
		|| ft_strequ(str, "....####........")
		|| ft_strequ(str, "........####....")
		|| ft_strequ(str, "............####"))
	{
		ft_strcpy(content, "####............");
		return (1);
	}
	if (ft_strequ(str, "#...#...#...#...")
		|| ft_strequ(str, ".#...#...#...#..")
		|| ft_strequ(str, "..#...#...#...#.")
		|| ft_strequ(str, "...#...#...#...#"))
	{
		ft_strcpy(content, "#...#...#...#...");
		return (1);
	}
	return (0);
}

int	check_j1(char *str, char *content)
{
	if (ft_strequ(str, ".#...#..##......")
		|| ft_strequ(str, "..#...#..##.....")
		|| ft_strequ(str, "...#...#..##....")
		|| ft_strequ(str, ".....#...#..##..")
		|| ft_strequ(str, "......#...#..##.")
		|| ft_strequ(str, ".......#...#..##"))
	{
		ft_strcpy(content, ".#...#..##......");
		return (1);
	}
	if (ft_strequ(str, "#...###.........")
		|| ft_strequ(str, ".#...###........")
		|| ft_strequ(str, "....#...###.....")
		|| ft_strequ(str, ".....#...###....")
		|| ft_strequ(str, "........#...###.")
		|| ft_strequ(str, ".........#...###"))
	{
		ft_strcpy(content, "#...###.........");
		return (1);
	}
	return (0);
}

int	check_j2(char *str, char *content)
{
	if (ft_strequ(str, "##..#...#.......")
		|| ft_strequ(str, ".##..#...#......")
		|| ft_strequ(str, "..##..#...#.....")
		|| ft_strequ(str, "....##..#...#...")
		|| ft_strequ(str, ".....##..#...#..")
		|| ft_strequ(str, "......##..#...#."))
	{
		ft_strcpy(content, "##..#...#.......");
		return (1);
	}
	if (ft_strequ(str, "###...#.........")
		|| ft_strequ(str, ".###...#........")
		|| ft_strequ(str, "....###...#.....")
		|| ft_strequ(str, ".....###...#....")
		|| ft_strequ(str, "........###...#.")
		|| ft_strequ(str, ".........###...#"))
	{
		ft_strcpy(content, "###...#.........");
		return (1);
	}
	return (0);
}
