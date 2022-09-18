/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dot_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:12:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/18 21:06:18 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	set_dot_struct(t_data *data, int i)
{
	int		j;
	char	**split2;

	j = 0;
	while (j < data->map.cols)
	{
		if (ft_strchr(data->split[j], ','))
		{
			split2 = ft_split(data->split[j], ',');
			data->dot[i][j].z = ft_atoi(split2[0]);
			linear_transformation(data, &data->map, i, j);
			data->dot[i][j].color = ft_htoi(split2[1]);
			ft_matrixfree((void **)split2);
		}
		else
		{
			data->dot[i][j].z = ft_atoi(data->split[j]);
			linear_transformation(data, &data->map, i, j);
			data->dot[i][j].color = WHITE_PIXEL - (4000 * data->dot[i][j].z);
			if (data->dot[i][j].color < 0)
				data->dot[i][j].color = WHITE_PIXEL;
		}
		j++;
	}
}
