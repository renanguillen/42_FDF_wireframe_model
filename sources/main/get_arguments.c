/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:12:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/24 19:17:55 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	coordinates(t_data *data, int i, int j)
{
	data->dot[i][j].x = data->scalex + (i * 3000 / data->area) + (j * 3000 / data->area);
	data->dot[i][j].y = data->scaley + (i * 3000 / data->area) - (j * 3000 / data->area);
	// data->dot[i][j].z *= (WINDOW_WIDTH / 4);
}

void	get_arguments(t_data *data, int i)
{
	int		j;
	char	**split2;

	j = 0;
	while (j < data->cols)
	{
		if (ft_strchr(data->split[j], ','))
		{
			split2 = ft_split(data->split[j], ',');
			coordinates(data, i, j);
			data->dot[i][j].z = ft_atoi(split2[0]);
			data->dot[i][j].color = htoi(split2[1]);
			ft_matrixfree((void **)split2);
		}
		else
		{
			coordinates(data, i, j);
			data->dot[i][j].z = ft_atoi(data->split[j]);
			data->dot[i][j].color = WHITE_PIXEL;
		}
		j++;
	}
}
