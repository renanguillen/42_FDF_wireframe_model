/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/02 22:09:21 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	bresenham(t_img *img, t_data *data, int i, int j)
{
	t_line	line;
	float	d;
	
	line.x = data->dot[i][j].x;
	line.y = data->dot[i][j].y;
	if (line.x < 0 || line.x > WINDOW_WIDTH || line.y < 0 || line.y > WINDOW_HEIGHT )
		return ;
	img_pix_put(img, line.x, line.y, data->dot[i][j].color);
	if (j == data->cols - 1)
		return ;
	else
	{
		line.xend = data->dot[i][j + 1].x;
		line.yend = data->dot[i][j + 1].y;
		line.dx = line.xend - line.x;
		line.dy = line.yend - line.y;
		d = (2 * line.dy) - line.dx;
		while (line.x < line.xend)
		{
			if (d <= 0)
			{
				d += (2 * line.dy);
				line.x++;
			}
			else
			{
				d += (2 * (line.dy - line.dx));
				line.x++;	
				line.y++;
			}
			if (line.x < 0 || line.x > WINDOW_WIDTH || line.y < 0 || line.y > WINDOW_HEIGHT )
				return ;
			img_pix_put(img, line.x, line.y, data->dot[i][j].color);
		}
	}
}


int render_line(t_img *img, t_data *data)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
			bresenham(img, data, i, j++);
		i++;
	}
	return (0);
}
