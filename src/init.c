/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:04:08 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 16:30:27 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_offset(t_info *info)
{
	double	x;
	double	y;
	double	alpha;

	info->space_x = 1344 / info->x_nb;
	info->space_y = 756 / info->y_nb;
	alpha = 30 * M_PI / 180;
	x = (info->x_nb / 2 * info->space_x) * cos(alpha)
		+ (info->y_nb / 2 * info->space_y) * cos(alpha +2.0944);
	y = (info->x_nb / 2 * info->space_x) * sin(alpha)
		+ (info->y_nb / 2 * info->space_y) * sin(alpha + 2.0944);
	info->offset_x = 960 - x;
	info->offset_y = 540 - y;
}

t_coord	*coordlast(t_coord *coord)
{
	if (!(coord))
		return (NULL);
	while (coord->next)
		coord = coord->next;
	return (coord);
}

void	add_back2(t_coord **coord, t_coord *node, t_coord *tmp, t_info *info)
{
	if (*coord == NULL)
	{
		*coord = node;
		(*coord)->next = NULL;
	}
	else
	{
		tmp = coordlast(*coord);
		tmp->next = node;
	}
	node->width = info->x_nb;
	node->height = info->y_nb;
	node->x_nb = info->token_x;
	node->y_nb = info->token_y;
}

void	coordadd_back(t_coord **coord, char *token, t_info *info)
{
	t_coord		*node;
	t_coord		*tmp;
	double		alpha;
	static int	count_x = 0;
	static int	count_y = 0;

	tmp = NULL;
	count_x = (info->token_x) * info->space_x;
	count_y = (info->token_y) * info->space_y;
	node = malloc(sizeof(t_coord));
	if (node == NULL)
	{
		free(info);
		lstclear_fdf(*coord, 1);
	}
	node->next = NULL;
	alpha = 30 * M_PI / 180;
	node->x = count_x * cos(alpha) + count_y * cos(alpha +2.0944)
		+ ft_atoi(token) * 3 * cos(alpha - 2.0944) + info->offset_x;
	node->y = count_x * sin(alpha) + count_y * sin(alpha + 2.0944)
		+ ft_atoi(token) * 3 * sin(alpha - 2.0944) + info->offset_y;
	node->color = 100000;
	get_color(node, token);
	add_back2(coord, node, tmp, info);
}
