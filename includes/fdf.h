/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:23:29 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 15:34:32 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../dep/ft_printf/includes/ft_printf.h"
# include "../dep/libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}				t_data;

typedef struct s_coord {
	int				x;
	int				y;
	int				color;
	int				x_nb;
	int				y_nb;
	int				width;
	int				height;
	struct s_coord	*next;
	struct t_data	*ptr_data;
	struct t_vars	*ptr_vars;
}					t_coord;

typedef struct s_info {
	int		token_x;
	int		token_y;
	int		x_nb;
	int		y_nb;
	int		space_x;
	int		space_y;
	int		offset_x;
	int		offset_y;
}			t_info;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	void			*img;
}	t_vars;

char			*get_next_line(int fd);
unsigned int	g_strlcpy(char *dest, const char *src, unsigned int size);
char			*ft_strdupchr(const char *src, char c);
char			*g_strjoin(char const *s1, char const *s2);
char			*g_strchr(const char *str, int c);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			create_window(t_coord *coord);
void			parsing(t_coord **coord, char *file);
void			lstclear_fdf(t_coord *coord, int finish);
void			free_tokens(char **tokens);
void			coordadd_back(t_coord **coord, char *token, t_info *info);
void			get_color(t_coord *coord, char *token);
size_t			ft_strstrlen(char **str);
void			draw_lines(t_coord *coord, t_data *data);
void			get_offset(t_info *info);

#endif
