/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/06 00:30:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/fdf.h"

void	bresenham(t_img *img, int color)
{
	int	pk;
	int	i;
	
	i = 0;
	img_pix_put(img, img->line.x, img->line.y, color);
	if(img->line.dx > img->line.dy)
	{
		pk = ((2 * img->line.dy) - img->line.dx);
		while(i < img->line.dx)
		{
			img->line.x++;
			if(pk < 0)
				pk += (2 * img->line.dy);
			else
			{
				img->line.y--;
				pk += ((2 * img->line.dy) - (2 * img->line.dx));
			}
			img_pix_put(img, img->line.x, img->line.y, color);
			i++;
		}
	}
	else
	{
		pk = ((2 * img->line.dx) - img->line.dy);
		while(i < img->line.dy)
		{
			img->line.y--;
			if(pk < 0)
				pk += (2 * img->line.dx);
			else
			{
				img->line.x++;
				pk += ((2 * img->line.dx) - (2 * img->line.dy));
			}
			img_pix_put(img, img->line.x, img->line.y, color);
			i++;
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
				img->line.dx = abs(img->line.xend - img->line.x);
				img->line.dy = abs(img->line.yend - img->line.y);
				bresenham(img, data->dot[i][j].color);
			}
			if (i != data->rows - 1)
			{
				img->line.x = data->dot[i][j].x;
				img->line.y = data->dot[i][j].y;
				img->line.xend = data->dot[i + 1][j].x;
				img->line.yend = data->dot[i + 1][j].y;
				img->line.dx = abs(img->line.xend - img->line.x);
				img->line.dy = abs(img->line.yend - img->line.y);
				bresenham(img, data->dot[i][j].color);
			}
			j++;
		}
		i++;
	}
	return (0);
}
