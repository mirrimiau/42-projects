/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:01 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/25 16:06:02 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_file_size(int fd, char *file)
{
	char	*buf;
	int		buf_size;
	int		ret;

	buf_size = HEADER_SIZE + PROG_NAME_LENGTH + NULL_TERM + CODE_SIZE \
	+ COMMENT_LENGTH + NULL_TERM;
	buf = (char *)malloc(sizeof(char) * buf_size);
	if (!buf)
		error_handler(MALLOC_PREFIX, strerror(errno), 0, 0);
	ret = read(fd, buf, buf_size);
	if (ret == -1)
	{
		free(buf);
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	}
	if (ret < buf_size)
	{
		free(buf);
		error_handler(FILE_TOO_SMALL, file, 0, 0);
	}
	ft_strdel(&buf);
	if (lseek(fd, 0, SEEK_SET) == -1)
		error_handler(LSEEK_PREFIX, strerror(errno), 0, 0);
}

static void	read_magic_header(int fd, char *file)
{
	unsigned char	buf[HEADER_SIZE];
	unsigned int	header;
	unsigned int	header_be;

	if (read(fd, buf, HEADER_SIZE) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	ft_memcpy(&header, buf, HEADER_SIZE);
	header_be = big_endian_converter(header, HEADER_SIZE);
	if (header_be != COREWAR_EXEC_MAGIC)
		error_handler(HEADER_ERROR, file, 0, 0);
}

void	parse_champion(t_info *info, char *file, int *id)
{
	int	player_index;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(OPEN_PREFIX, strerror(errno), 0, 0);
	check_file_size(fd, file);
	read_magic_header(fd, file);
	info->champion_count++;
	if (info->champion_count > MAX_PLAYERS)
		error_handler(TOO_MANY_PLAYERS, NULL, 0, 0);
	player_index = set_player_id(id, info->champions);
	save_champion(fd, &info->champions[player_index], file);
	if (close(fd) == -1)
		error_handler(CLOSE_PREFIX, strerror(errno), 0, 0);
}
