/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:15:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/09 00:02:01 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	get_lines(int argc, char **argv, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = check_args(argc, argv);
	data->rows = count_lines(argv[1]);
	data->lines = malloc(sizeof (char *) * (data->rows + 1));
	found_error ((void **)data->lines);
	while (i < data->rows)
		data->lines[i++] = ft_get_next_line(fd);
	data->lines[i] = NULL;
	i = 0;
	data->split = ft_split(data->lines[i], ' ');
	data->cols = ft_splitlen(data->split);
	ft_matrixfree((void **)data->split);
	data->dot = malloc(sizeof (t_dot *) * data->rows);
	data->diagonal = sqrt(pow(data->rows, 2) + pow(data->cols, 2));
	data->scalei = 0.5 * (WINDOW_HEIGHT / data->diagonal);
	data->scalej = 0.5 * (WINDOW_WIDTH / data->diagonal);
	printf("Scalei:%f\nScalej:%f\n", data->scalei, data->scalej);
}
