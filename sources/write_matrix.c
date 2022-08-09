/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:10:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/09 20:10:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_matrix(t_matrix *matrix)
{
	int		i;

	i = 0;
	while (matrix->lines[i])
	{
		matrix->dot[i] = malloc(sizeof (t_dot) * matrix->col_count);
		found_error((void **) &matrix->dot[i]);
		matrix->split = ft_split(matrix->lines[i], ' ');
		get_arguments(matrix, i);
		ft_matrixfree((void **)matrix->split);
		i++;
	}
}
