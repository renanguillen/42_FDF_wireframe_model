/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:01:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/01 17:14:20 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	coordinates(t_data *data, int i, int j)
{
	data->dot[i][j].x = ((WINDOW_HEIGHT / 2) + (i * data->scalei) + (j * data->scalei) - (data->cols * data->scalei)) - data->dot[i][j].z;
	data->dot[i][j].y = ((WINDOW_WIDTH / 1.2) - (i * data->scalej) + (j * data->scalej) - (data->rows * data->scalej));		
}