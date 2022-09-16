/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:56:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 23:00:47 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

int	draw_image(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (data->key.press)
	{
		clear_window(&data->img);
		data->key.press = 0;
	}
	bresenham_line_drawing(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}
