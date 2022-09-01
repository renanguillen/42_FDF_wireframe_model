/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/01 23:27:45 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int render_line(t_img *img, t_data *data)
{
	int	i;
	int	j;
	double x;
	double y;
	
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			x = data->dot[i][j].y;
			y = data->dot[i][j].x;
			if (x < 0 || y < 0 || j > WINDOW_WIDTH || x > WINDOW_HEIGHT)
				return (0);
			img_pix_put(img, y, x, data->dot[i][j].color);
			j++;
		}
		i++;
	}
	return (0);
}
