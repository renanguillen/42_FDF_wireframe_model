/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:54:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/13 22:21:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPES_H
# define FDF_PROTOTYPES_H

int		check_args(int argc, char **argv);
int		count_lines(char *argv);
void	get_lines(int argc, char **argv, t_data *data);
void	found_error(void **pointer);
void	get_arguments(t_data *data, int i);
void	write_matrix(t_data *data);
void	put_a_pixel(t_img *img);
void	bresenham_line_drawing(t_img *img, t_data *data);
int		handle_x_button(t_data *data);
int		handle_keypress(int keypress, t_data *data);
int		draw_image(t_data *data);
void	lin_transf(t_data *data, int i, int j);

#endif