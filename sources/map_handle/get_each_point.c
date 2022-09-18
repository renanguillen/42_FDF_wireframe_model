/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_each_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:10:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/18 21:04:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	get_each_point(t_data *data)
{
	int	i;

	i = 0;
	while (data->lines[i])
	{
		data->dot[i] = malloc(sizeof (t_dot) * data->map.cols);
		found_error((void **) &data->dot);
		data->split = ft_split(data->lines[i], ' ');
		set_dot_struct(data, i++);
		ft_matrixfree((void **)data->split);
	}
	data->dot[i] = NULL;
	ft_matrixfree((void **)data->lines);
}
