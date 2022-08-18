/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:12:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/18 20:14:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
			data->dot[i][j].x = ((i - 1) * data->constant) + 50;
			data->dot[i][j].y = (j * data->constant) + 50;
			data->dot[i][j].z = ft_atoi(split2[0]);
			data->dot[i][j].color = htoi(split2[1]);
			ft_matrixfree((void **)split2);
		}
		else
		{
			data->dot[i][j].x = ((i - 1) * data->constant) + 50;
			data->dot[i][j].y = (j * data->constant) + 50;
			data->dot[i][j].z = ft_atoi(data->split[j]);
			data->dot[i][j].color = WHITE_PIXEL;
		}
		j++;
	}
}
