/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_transf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:01:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 21:12:16 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	lin_transf(t_data *data, int i, int j)
{
	data->dot[i][j].y = ((WINDOW_HEIGHT / 2) - (data->map.cols * data->map.scalei));
	data->dot[i][j].y -= (data->dot[i][j].z);
	data->dot[i][j].y += (i * data->map.scalei);
	data->dot[i][j].y += (j * data->map.scalei);
	data->dot[i][j].x = ((WINDOW_WIDTH / 1.2) - (data->map.rows * data->map.scalej));
	data->dot[i][j].x -= (i * data->map.scalej);
	data->dot[i][j].x += (j * data->map.scalej);
}
