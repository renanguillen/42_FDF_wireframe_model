/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:45:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/19 22:39:06 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700
# define MLX_ERROR 1
# define WHITE_PIXEL 0xFFFFFF

# include <stdlib.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libraries/42_libft/libft.h"
# include <math.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_win
{
	int	wid;
	int hei;
}	t_win;

typedef struct s_dot
{
	double	x;
	double	y;
	double	z;
	int	color;
}	t_dot;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_win	win;
	int		rows;
	int		cols;
	char	**lines;
	char	**split;
	t_dot	**dot;
	int		constant;
}	t_data;

int		check_args(int argc, char **argv);
int		count_lines(char *argv);
void	get_lines(int argc, char **argv, t_data *data);
void	found_error(void **pointer);
void	get_arguments(t_data *data, int i);
void	write_matrix(t_data *data);
int		htoi(char s[]);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_line(t_img *img, t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_button(t_data *data);
int		render(t_data *data);
void	get_scale(t_data *data);

#endif