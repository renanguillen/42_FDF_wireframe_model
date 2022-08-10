/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:12:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/10 20:21:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_arguments(t_data *data, int i)
{
	int		j;
	char	**split2;

	j = 0;
	while (j < data->matrix.col_count)
	{
		if (ft_strchr(data->matrix.split[j], ','))
		{
			split2 = ft_split(data->matrix.split[j], ',');
			data->matrix.dot[i][j].value = ft_atoi(split2[0]);
			data->matrix.dot[i][j].color = htoi(split2[1]);
			ft_matrixfree((void **)split2);
		}
		else
		{
			data->matrix.dot[i][j].value = ft_atoi(data->matrix.split[j]);
			data->matrix.dot[i][j].color = WHITE_PIXEL;
		}
		j++;
	}
}
