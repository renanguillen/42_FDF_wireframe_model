/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:10:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/18 21:09:35 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	write_matrix(t_data *data)
{
	int		i;

	i = 0;
	while (data->lines[i])
	{
		data->dot[i] = malloc(sizeof (t_dot) * data->cols);
		found_error((void **) &data->dot);
		data->split = ft_split(data->lines[i], ' ');
		get_arguments(data, i++);
		ft_matrixfree((void **)data->split);
	}
	get_scale(data);
}
