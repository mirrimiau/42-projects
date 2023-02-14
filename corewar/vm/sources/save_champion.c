/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:28 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/27 14:06:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	save_code(int fd, t_champion *champion, char *file)
{
	char	check[1];
	int		ret;

	ret = read(fd, champion->code, CHAMP_MAX_SIZE);
	if (ret == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	if (ret < CHAMP_MAX_SIZE && (unsigned int)ret != champion->code_size)
		error_handler(CODE_SIZE_DIFF, file, 0, 0);
	if (champion->code_size > CHAMP_MAX_SIZE)
		error_handler(CHAMP_TOO_BIG, file, champion->code_size, CHAMP_MAX_SIZE);
	if (read(fd, check, 1) > 0)
		error_handler(CODE_SIZE_DIFF, file, 0, 0);
}

static void	save_comment(int fd, t_champion *champion)
{
	unsigned char	buf[NULL_TERM];

	if (read(fd, champion->comment, COMMENT_LENGTH) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	if (read(fd, buf, NULL_TERM) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
}

static void	save_code_size(int fd, t_champion *champion)
{
	unsigned char	buf[CODE_SIZE];
	unsigned int	size;
	unsigned int	size_be;

	if (read(fd, buf, CODE_SIZE) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	ft_memcpy(&size, buf, CODE_SIZE);
	size_be = big_endian_converter(size, CODE_SIZE);
	champion->code_size = size_be;
}

static void	save_name(int fd, t_champion *champion)
{
	unsigned char	buf[NULL_TERM];

	if (read(fd, champion->name, PROG_NAME_LENGTH) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	if (read(fd, buf, NULL_TERM) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
}

void	save_champion(int fd, t_champion *champion, char *file)
{
	save_name(fd, champion);
	save_code_size(fd, champion);
	save_comment(fd, champion);
	save_code(fd, champion, file);
}
