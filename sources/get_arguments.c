/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:12:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/09 22:44:00 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_arguments(t_matrix *matrix, int i)
{
	int		j;
	char	**split2;

	j = 0;
	while (j < matrix->col_count)
	{
		if (ft_strchr(matrix->split[j], ','))
		{
			split2 = ft_split(matrix->split[j], ',');
			matrix->dot[i][j].value = ft_atoi(split2[0]);
			matrix->dot[i][j].color = RED_PIXEL;
			ft_matrixfree((void **)split2);
		}
		else
		{
			matrix->dot[i][j].value = ft_atoi(matrix->split[j]);
			matrix->dot[i][j].color = GREEN_PIXEL;
		}
		j++;
	}
}
