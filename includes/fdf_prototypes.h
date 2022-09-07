/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:54:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/07 20:55:38 by ridalgo-         ###   ########.fr       */
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
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_line(t_img *img, t_data *data);
int		handle_mousekey(t_data *data);
int		handle_button(int keypress, t_data *data);
int		render(t_data *data);
void	lin_transf(t_data *data, int i, int j);

#endif