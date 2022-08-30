/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/25 21:35:49 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int render_line(t_img *img, t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			x = (WINDOW_WIDTH / 2) - (data->cols * data->scalej / 2) + (j * data->scalej);
			y = (WINDOW_HEIGHT / 2) - (data->rows * data->scalei  / 2) + (i *  data->scalei);
			img_pix_put(img, x, y, data->dot[i][j].color);
			j++;
		}
		i++;
	}
	return (0);
}
