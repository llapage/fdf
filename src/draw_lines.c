/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:49:21 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 17:20:46 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line_exec(t_coord *coord, t_data *data)
{
	double	steps;
	double	x_step;
	double	y_step;
	double	step;

	steps = abs(data->y2 - data->y1);
	if (abs(data->x2 - data->x1) > abs(data->y2 - data->y1))
		steps = abs(data->x2 - data->x1);
	x_step = (data->x2 - data->x1) / steps;
	y_step = (data->y2 - data->y1) / steps;
	step = 0;
	while (step < steps + 1)
	{
		my_mlx_pixel_put(data, data->x1 + step * x_step, data->y1
			+ step * y_step, coord->color);
		step++;
	}
}

void	draw_lines2(t_coord *tmp, t_coord *cur, t_data *data)
{
	int		no_tmp;
	int		i;

	i = 0;
	no_tmp = 0;
	if (cur->x_nb != cur->width - 1)
		line_exec(cur, data);
	while (i < cur->width)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			no_tmp = 1;
		i++;
	}
	data->x2 = tmp->x;
	data->y2 = tmp->y;
	if (no_tmp == 0)
		line_exec(cur, data);
}

void	draw_lines(t_coord *coord, t_data *data)
{
	t_coord	*cur;
	t_coord	*tmp;

	cur = coord;
	while (cur)
	{
		tmp = cur;
		data->x1 = cur->x;
		data->y1 = cur->y;
		if (cur->next)
		{
			data->x2 = cur->next->x;
			data->y2 = cur->next->y;
		}
		else
			break ;
		draw_lines2(tmp, cur, data);
		cur = cur->next;
	}
}
