/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:15:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/09 20:15:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_lines(int argc, char **argv, t_matrix *matrix)
{
	int	fd;
	int	i;

	i = 0;
	fd = check_args(argc, argv);
	matrix->row_count = count_lines(argv[1]);
	matrix->lines = malloc(sizeof (char *) * (matrix->row_count + 1));
	found_error ((void **)matrix->lines);
	while (i < matrix->row_count)
		matrix->lines[i++] = get_next_line(fd);
	matrix->lines[i] = NULL;
	i = 0;
	matrix->split = ft_split(matrix->lines[i], ' ');
	matrix->col_count = ft_splitlen(matrix->split);
	ft_matrixfree((void **)matrix->split);
}
