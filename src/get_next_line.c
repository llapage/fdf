/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:04:07 by llapage           #+#    #+#             */
/*   Updated: 2023/06/27 14:11:21 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*g_memset(void *b, int c, size_t len)
{
	unsigned char			*a;

	a = (unsigned char *) b;
	while (len > 0)
	{
		*a++ = (unsigned char)c;
		len--;
	}
	return (b);
}

static int	ft_read(char *buf, int fd, char **line)
{
	int		ret;
	char	*tmp;

	tmp = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret > 0)
		buf[ret] = '\0';
	if (!(*line))
	{
		*line = ft_strdupchr(buf, 0);
		if (!(*line))
			return (-1);
	}
	else if (ret > 0)
	{
		tmp = ft_strdupchr(*line, 0);
		free(*line);
		if (!(tmp))
			return (-1);
		*line = g_strjoin(tmp, buf);
		free(tmp);
		if (!(*line))
			return (-1);
	}
	return (ret);
}

char	*check_ret(char *buf, int ret, char **line, char **tmp)
{
	if (ret < 0)
		return (NULL);
	if (ret <= 0 && (!*line[0]))
	{
		g_memset(buf, 0, BUFFER_SIZE + 1);
		free(*line);
		return (NULL);
	}
	if (ret == 0)
	{
		g_memset(buf, 0, BUFFER_SIZE + 1);
		*tmp = ft_strdupchr(*line, '\n');
		free(*line);
		return (*tmp);
	}
	return (NULL);
}

int	ft_start(char *buf, int fd, char **line)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || fd > OPEN_MAX - 1)
	{
		if (fd >= 0 && buf && fd < OPEN_MAX - 1)
			g_memset(buf, 0, BUFFER_SIZE);
		return (0);
	}
	if (buf[0])
	{
		*line = ft_strdupchr(buf, '\n');
		if (!*line)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	int			ret;
	char		*line;
	char		*tmp;

	ret = 1;
	line = 0;
	if (!ft_start(buf[fd], fd, &line))
		return (NULL);
	while (ret > 0)
	{
		if (line && g_strchr(line, '\n'))
		{
			g_strlcpy(buf[fd], g_strchr(buf[fd], '\n') + 1, BUFFER_SIZE + 1);
			tmp = ft_strdupchr(line, '\n');
			free(line);
			return (tmp);
		}
		else
			ret = ft_read(&buf[fd][0], fd, &line);
	}
	return (check_ret(&buf[fd][0], ret, &line, &tmp));
}
