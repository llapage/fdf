/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:24:58 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 17:39:24 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 17)
		close_window(vars);
	return (0);
}

void	put_pixels(t_coord *coord, t_data img)
{
	t_coord	*tmp;

	tmp = coord;
	while (tmp)
	{
		my_mlx_pixel_put(&img, tmp->x, tmp->y, tmp->color);
		tmp = tmp->next;
	}
	tmp = coord;
	if (tmp)
		draw_lines(tmp, &img);
}

void	create_window(t_coord *coord)
{
	t_vars	vars;
	t_data	img;
	t_coord	*tmp;

	tmp = coord;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		lstclear_fdf(coord, 1);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fdf");
	if (!vars.win)
		lstclear_fdf(coord, 1);
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	if (!img.img)
		lstclear_fdf(coord, 1);
	vars.img = img.img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_pixels(tmp, img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	lstclear_fdf(coord, 0);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1920 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
