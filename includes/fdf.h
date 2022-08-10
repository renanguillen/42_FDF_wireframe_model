/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:45:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/10 20:21:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 900
# define MLX_ERROR 1
# define WHITE_PIXEL 0x8000FF

# include <stdlib.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libraries/42_libft/libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_dot
{
	int				value;
	int				color;
}	t_dot;

typedef struct s_matrix
{
	int		row_count;
	int		col_count;
	char	**lines;
	char	**split;
	t_dot	**dot;
}	t_matrix;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			cur_img;
	t_matrix	matrix;
}	t_data;

int		check_args(int argc, char **argv);
int		count_lines(char *argv);
void	get_lines(int argc, char **argv, t_data *data);
void	found_error(void **pointer);
void	get_arguments(t_data *data, int i);
void	write_matrix(t_data *data);
int		htoi(char s[]);

#endif