/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 23:12:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(int argc, char **argv)
{
	t_data	data;

	get_lines(check_args(argc, argv), argv[1], &data, &data.map);
	found_error((void **) data.dot);
	write_matrix(&data);
	win_initialization(&data);
	handle_hooks(&data);
	mlx_loop(data.mlx_ptr);
}
