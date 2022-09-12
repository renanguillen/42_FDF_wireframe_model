/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_drawing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/12 19:25:43 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

static void	low_slope(t_img *img)
{
	int	decisive;
	int	ppl;

	decisive = 0;
	ppl = 0;
	put_a_pixel(img);
	decisive = (2 * img->dy) - img->dx;
	while (ppl < img->dx)
	{
		ppl++;
		img->x0 += img->sx;
		if (decisive < 0)
			decisive += (2 * img->dy);
		else
		{
			img->y0 += img->sy;
			decisive += ((2 * img->dy) - (2 * img->dx));
		}
		put_a_pixel(img);
	}
}

static void	high_slope(t_img *img)
{
	int	decisive;
	int	ppl;

	decisive = 0;
	ppl = 0;
	put_a_pixel(img);
	decisive = (2 * img->dx) - img->dy;
	while (ppl < img->dy)
	{
		ppl++;
		img->y0 += img->sy;
		if (decisive < 0)
			decisive += (2 * img->dx);
		else
		{
			img->x0 += img->sx;
			decisive += ((2 * img->dx) - (2 * img->dy));
		}
		put_a_pixel(img);
	}
}

static void	set_line_angle(t_img *img)
{
	img->dx = (img->x1 - img->x0);
	if (img->dx > 0)
		img->sx = 1;
	else
		img->sx = -1;
	img->dx = abs(img->dx);
	img->dy = (img->y1 - img->y0);
	if (img->dy > 0)
		img->sy = 1;
	else
		img->sy = -1;
	img->dy = abs(img->dy);
	if (img->dx > img->dy)
		low_slope(img);
	else
		high_slope(img);
}

static void	set_points(t_img *img, t_data *data, int i, int j)
{
	if (j != data->cols - 1)
	{
		img->x0 = data->dot[i][j].x;
		img->y0 = data->dot[i][j].y;
		img->x1 = data->dot[i][j + 1].x;
		img->y1 = data->dot[i][j + 1].y;
		img->color = data->dot[i][j].color;
		set_line_angle(img);
	}
	if (i != data->rows -1)
	{
		img->x0 = data->dot[i][j].x;
		img->y0 = data->dot[i][j].y;
		img->x1 = data->dot[i + 1][j].x;
		img->y1 = data->dot[i + 1][j].y;
		img->color = data->dot[i][j].color;
		set_line_angle(img);
	}
}

void	bresenham_line_drawing(t_img *img, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			set_points(img, data, i, j);
			j++;
		}
		i++;
	}
}
