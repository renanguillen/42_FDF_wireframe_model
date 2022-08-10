/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:15:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/10 19:08:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_lines(int argc, char **argv, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = check_args(argc, argv);
	data->matrix.row_count = count_lines(argv[1]);
	data->matrix.lines = malloc(sizeof (char *) * (data->matrix.row_count + 1));
	found_error ((void **)data->matrix.lines);
	while (i < data->matrix.row_count)
		data->matrix.lines[i++] = get_next_line(fd);
	data->matrix.lines[i] = NULL;
	i = 0;
	data->matrix.split = ft_split(data->matrix.lines[i], ' ');
	data->matrix.col_count = ft_splitlen(data->matrix.split);
	ft_matrixfree((void **)data->matrix.split);
}
