/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:15:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 21:25:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	get_lines(int fd, char *filename, t_data *data)
{
	int	i;

	i = 0;
	data->map.rows = count_lines(filename);
	data->lines = malloc(sizeof (char *) * (data->map.rows + 1));
	found_error ((void **)data->lines);
	while (i < data->map.rows)
		data->lines[i++] = ft_get_next_line(fd);
	data->lines[i] = NULL;
	i = 0;
	data->split = ft_split(data->lines[i], ' ');
	data->map.cols = ft_splitlen(data->split);
	ft_matrixfree((void **)data->split);
	data->dot = malloc(sizeof (t_dot *) * (data->map.rows + 1));
	data->map.diagonal = sqrt(pow(data->map.rows, 2) + pow(data->map.cols, 2));
	data->map.scalei = 0.5 * (WINDOW_HEIGHT / data->map.diagonal);
	data->map.scalej = 0.5 * (WINDOW_WIDTH / data->map.diagonal);
}
