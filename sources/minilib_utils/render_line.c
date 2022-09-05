/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/06 01:25:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/fdf.h"

void	bresenham(t_img *img, int color)
{
	int	eps;
	
	eps = 0;
	img_pix_put(img, img->line.x, img->line.y, color);
	if (img->line.dx > img->line.dy)
	{
		if (img->line.sx < 0)
		{
			while(img->line.x >= img->line.xend)
			{
				eps += img->line.dy;
				if ((2 * eps) >= img->line.dx)
				{
					img->line.y += img->line.sy;
					eps -= img->line.dx;
				}
				img->line.x += img->line.sx;
				img_pix_put(img, img->line.x, img->line.y, color);
			}
		}
		else
		{
			while(img->line.x <= img->line.xend)
			{
				eps += img->line.dy;
				if ((2 * eps) >= img->line.dx)
				{
					img->line.y += img->line.sy;
					eps -= img->line.dx;
				}
				img->line.x += img->line.sx;
				img_pix_put(img, img->line.x, img->line.y, color);
			}
		}
	}
	else
	{
		if (img->line.sy < 0)
		{
			while(img->line.y >= img->line.yend)
			{
				eps += img->line.dx;
				if ((2 * eps) >= img->line.dy)
				{
					img->line.x += img->line.sx;
					eps -= img->line.dy;
				}
				img->line.y += img->line.sy;
				img_pix_put(img, img->line.x, img->line.y, color);
			}
		}
		else
		{
			while(img->line.x <= img->line.xend)
			{
				eps += img->line.dy;
				if ((2 * eps) >= img->line.dx)
				{
					img->line.y += img->line.sy;
					eps -= img->line.dx;
				}
				img->line.x += img->line.sx;
				img_pix_put(img, img->line.x, img->line.y, color);
			}
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
		{
			if (j != data->cols - 1)
			{
				img->line.x = data->dot[i][j].x;
				img->line.y = data->dot[i][j].y;
				img->line.xend = data->dot[i][j + 1].x;
				img->line.yend = data->dot[i][j + 1].y;
				img->line.dx = (img->line.xend - img->line.x);
				if (img->line.dx > 0)
					img->line.sx = 1;
				else
					img->line.sx = 1;
				img->line.dx = abs(img->line.dx);
				img->line.dy = (img->line.yend - img->line.y);
				if (img->line.dy > 0)
					img->line.sy = 1;
				else
					img->line.sy = 1;
				img->line.dy = abs(img->line.dy);
				bresenham(img, data->dot[i][j].color);
			}
			if (i != data->rows - 1)
			{
				img->line.x = data->dot[i][j].x;
				img->line.y = data->dot[i][j].y;
				img->line.xend = data->dot[i + 1][j].x;
				img->line.yend = data->dot[i + 1][j].y;
				img->line.dx = (img->line.xend - img->line.x);
				if (img->line.dx > 0)
					img->line.sx = 1;
				else
					img->line.sx = 1;
				img->line.dx = abs(img->line.dx);
				img->line.dy = (img->line.yend - img->line.y);
				if (img->line.dy > 0)
					img->line.sy = 1;
				else
					img->line.sy = 1;
				img->line.dy = abs(img->line.dy);
				bresenham(img, data->dot[i][j].color);
			}
			j++;
		}
		i++;
	}
	return (0);
}
