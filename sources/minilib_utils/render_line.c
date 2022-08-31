/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/31 21:41:15 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int render_line(t_img *img, t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int dots;
	
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			dots = 0;
			while (dots < data->scalej && j < data->cols - 1)
			{
				x = (WINDOW_WIDTH / 2) - (data->scalej * data->cols / 2) + (i * data->scalej) + (j * data->scalej);
				y = (WINDOW_HEIGHT / 2) - (data->scalei * data->rows  / 2) + (i *  data->scalei) - (j * data->scalei);
				img_pix_put(img, x + dots++, y, data->dot[i][j].color);
			}
			dots = 0;
			while (dots < data->scalei && i < data->rows - 1)
			{
				x = (WINDOW_WIDTH / 2) - (data->scalej * data->cols / 2) + (i * data->scalej) + (j * data->scalej);
				y = (WINDOW_HEIGHT / 2) - (data->scalei * data->rows  / 2) + (i *  data->scalei) - (j * data->scalei);
				img_pix_put(img, x, y + dots++, data->dot[i][j].color);
			}
			j++;
		}
		i++;
	}
	return (0);
}
