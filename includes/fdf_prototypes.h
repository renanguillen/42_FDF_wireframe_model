/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:54:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/18 21:06:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPES_H
# define FDF_PROTOTYPES_H

int		check_args(int argc, char **argv);
int		count_lines(char *filename);
void	get_lines(int fd, char *filename, t_data *data, t_map *map);
void	found_error(void **pointer);
void	set_dot_struct(t_data *data, int i);
void	get_each_point(t_data *data);
void	put_a_pixel(t_img *img, t_line line);
void	bresenham_line_drawing(t_data *data);
int		handle_x_button(t_data *data);
int		handle_keypress(int keypress, t_data *data);
int		draw_image(t_data *data);
void	linear_transformation(t_data *data, t_map *map, int i, int j);
void	free_data(t_data *data);
int		win_initialization(t_data *data);
void	handle_hooks(t_data *data);
void	clear_window(t_img *img);

#endif