/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:20:03 by altikka           #+#    #+#             */
/*   Updated: 2022/12/06 13:52:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	valid_file(int argc, char *filename)
{
	char	*ext;

	if (argc != 2 && argc != 3)
		return (0);
	ext = ft_strrchr(filename, '.');
	return (ft_strnequ(ext, ".s", 3));
}

void	panic(const char *msg)
{
	ft_dprintf(2, "%s\n", msg);
	exit(EXIT_FAILURE);
}
