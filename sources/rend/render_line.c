/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:51:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/23 19:43:30 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int render_line(t_img *img, t_data *data)
{
	int	i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			img_pix_put(img, data->dot[i][j].x, data->dot[i][j].y, data->dot[i][j].color);
			// img_pix_put(img, data->dot[i][j].x, data->dot[i][j].z, data->dot[i][j].color);
			j++;
		}
		i++;
	}
	return (0);
}
