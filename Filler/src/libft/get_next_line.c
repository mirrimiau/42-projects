/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:50:03 by mapostol          #+#    #+#             */
/*   Updated: 2021/12/13 11:50:04 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	first_delimiter(int fd, char buf[fd][BUFF_SIZE + 1])
{
	int	ret;

	ret = 0;
	while (buf[fd][ret])
	{
		if (buf[fd][ret] == '\n')
			return (ret);
		ret++;
	}
	return (-1);
}

int	read_from_buffer(int len, int fd, char buf[MAX_FD][BUFF_SIZE + 1],
	char **line)
{
	char	*temp;

	if (len == 0)
	{
		ft_strcpy(buf[fd], buf[fd] + 1);
		*line = ft_strdup("\0");
		return (1);
	}
	temp = (char *) malloc(sizeof(char) * (size_t)(len + 1));
	if (temp == NULL)
		return (-1);
	ft_strncpy(temp, buf[fd], (size_t) len);
	temp[len] = '\0';
	*line = temp;
	ft_strcpy(buf[fd], buf[fd] + len + 1);
	return (1);
}

int	read_until_delimiter(int ret, int fd, char buf[fd][BUFF_SIZE + 1],
	char **line)
{
	int		len;
	char	*temp;

	while (ret)
	{
		buf[fd][ret] = '\0';
		len = first_delimiter(fd, buf);
		temp = ft_strdup(*line);
		free (*line);
		if (len != -1)
			buf[fd][len] = '\0';
		*line = ft_strjoin(temp, buf[fd]);
		free (temp);
		if (len != -1)
		{
			ft_strcpy(buf[fd], buf[fd] + len + 1);
			break ;
		}
		ret = (int) read(fd, buf[fd], BUFF_SIZE);
	}
	return (ret);
}

int	create_next_line(int fd, char buf[fd][BUFF_SIZE + 1], char **line)
{
	int		ret;

	*line = ft_strdup(buf[fd]);
	ret = (int) read(fd, buf[fd], BUFF_SIZE);
	if (ret == -1 || *line == NULL)
		return (-1);
	ret = read_until_delimiter(ret, fd, buf, line);
	if (ret == 0)
		ft_strcpy(buf[fd], "\0");
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	buf[MAX_FD][BUFF_SIZE + 1];
	int			ret;
	int			len;

	if (fd < 0 || fd > MAX_FD)
		return (-1);
	buf[fd][BUFF_SIZE] = '\0';
	if (!buf[fd][0])
	{
		ret = (int) read(fd, buf[fd], BUFF_SIZE);
		if (ret < 1)
			return (ret);
	}
	len = first_delimiter(fd, buf);
	if (len != (int) ft_strlen(buf[fd]) && len != -1)
	{
		ret = read_from_buffer(len, fd, buf, line);
		if (ret == -1)
			return (-1);
	}
	else
		ret = create_next_line(fd, buf, line);
	if (ret != -1)
		return (1);
	return (ret);
}
