/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_transf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:01:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 21:35:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	lin_transf(t_data *data, t_map *map, int i, int j)
{
	data->dot[i][j].y = ((WINDOW_HEIGHT / 2) - (map->cols * map->scalei));
	data->dot[i][j].y -= (data->dot[i][j].z);
	data->dot[i][j].y += (i * map->scalei);
	data->dot[i][j].y += (j * map->scalei);
	data->dot[i][j].x = ((WINDOW_WIDTH / 1.2) - (map->rows * map->scalej));
	data->dot[i][j].x -= (i * map->scalej);
	data->dot[i][j].x += (j * map->scalej);
}
