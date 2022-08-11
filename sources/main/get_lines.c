/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:15:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/11 15:48:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
		data->lines[i++] = get_next_line(fd);
	data->lines[i] = NULL;
	i = 0;
	data->split = ft_split(data->lines[i], ' ');
	data->cols = ft_splitlen(data->split);
	ft_matrixfree((void **)data->split);
}
