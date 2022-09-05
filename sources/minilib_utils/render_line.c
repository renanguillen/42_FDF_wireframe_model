/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/05 20:30:06 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/fdf.h"

void	bresenham(t_img *img, int color)
{
	float	d;
	
	img_pix_put(img, img->line.x, img->line.y, color);
	if (img->line.slope < 1)
	{
		d = (2 * img->line.dy) - img->line.dx;
		while (img->line.x < img->line.xend)
		{
			if (d < 0)
				d += (2 * img->line.dy);
			else
			{
				d += (2 * (img->line.dy - img->line.dx));
				img->line.y--;
			}
			img->line.x++;
			img_pix_put(img, img->line.x, img->line.y, color);
		}
	}
	else if (img->line.slope >= 1)
	{
		d = (2 * img->line.dx) - img->line.dy;
		while (img->line.y < img->line.yend)
		{
			if (d < 0)
				d += (2 * img->line.dx);
			else
			{
				d += (2 * (img->line.dx - img->line.dy));
				img->line.x++;
			}
			img->line.y++;
			img_pix_put(img, img->line.x, img->line.y, color);
		}
	}
	else
		return ;
}


int render_line(t_img *img, t_data *data)
{
	int		i;
	int		j;
	static int global = 0;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (j != data->cols - 1)
			{
				img->line.x = data->dot[i][j].x;
				img->line.y = data->dot[i][j].y;
				img->line.xend = data->dot[i][j + 1].x;
				img->line.yend = data->dot[i][j + 1].y;
				img->line.dx = (img->line.xend - img->line.x);
				img->line.dy = (img->line.yend - img->line.y);
				img->line.slope = img->line.dy / img->line.dx;
				bresenham(img, data->dot[i][j].color);
			}
			if (i != data->rows - 1)
			{
				img->line.x = data->dot[i][j].x;
				img->line.y = data->dot[i][j].y;
				img->line.xend = data->dot[i + 1][j].x;
				img->line.yend = data->dot[i + 1][j].y;
				img->line.dx = (img->line.xend - img->line.x);
				img->line.dy = (img->line.yend - img->line.y);
				img->line.slope = img->line.dy / img->line.dx;
				bresenham(img, data->dot[i][j].color);
			}
			j++;
		}
		i++;
	}
	return (0);
}
