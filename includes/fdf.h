/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:45:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/07 20:43:24 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
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
# include "structs.h"


int		check_args(int argc, char **argv);
int		count_lines(char *argv);
void	get_lines(int argc, char **argv, t_data *data);
void	found_error(void **pointer);
void	get_arguments(t_data *data, int i);
void	write_matrix(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_line(t_img *img, t_data *data);
int		handle_mousekey(t_data *data);
int		handle_button(int keypress, t_data *data);
int		render(t_data *data);
void	lin_transf(t_data *data, int i, int j);

#endif