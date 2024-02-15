/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:28:31 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 17:22:18 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	hex_to_dec(char *color)
{
	int	decimalnumber;
	int	i;
	int	len;
	int	val;

	i = 0;
	val = 0;
	decimalnumber = 0;
	len = ft_strlen(color);
	len--;
	while (color[i] != '\0')
	{
		if (color[i] >= '0' && color[i] <= '9')
			val = color[i] - 48;
		else if (color[i] >= 'a' && color[i] <= 'f')
			val = color[i] - 97 + 10;
		else if (color[i] >= 'A' && color[i] <= 'F')
			val = color[i] - 65 + 10;
		decimalnumber += val * pow(16, len);
		len--;
		i++;
	}
	return (decimalnumber);
}

void	get_color(t_coord *coord, char *token)
{
	char	*color;

	if (!ft_strchr(token, ','))
		return ;
	color = ft_strchr(token, ',');
	if (!color[1])
		return ;
	color = color + 1;
	coord->color = hex_to_dec(color);
}

static void	line_to_struct(t_coord **coord, char *line, t_info *info)
{
	char		**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		free(info);
		lstclear_fdf(*coord, 1);
	}
	info->x_nb = ft_strstrlen(tokens);
	info->token_x = 0;
	get_offset(info);
	while (tokens[info->token_x])
	{
		if (tokens[info->token_x][0] != '\n')
			coordadd_back(coord, tokens[info->token_x], info);
		info->token_x++;
	}
	free_tokens(tokens);
	info->token_y++;
}

static void	width_height(t_info *info, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(info);
		exit(1);
	}
	line = get_next_line(fd);
	info->y_nb = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		info->y_nb++;
	}
	close(fd);
}

void	parsing(t_coord **coord, char *file)
{
	char	*line;
	int		fd;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		exit(1);
	width_height(info, file);
	info->token_y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(info);
		lstclear_fdf(*coord, 1);
	}
	line = get_next_line(fd);
	while (line)
	{
		line_to_struct(coord, line, info);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(info);
}
