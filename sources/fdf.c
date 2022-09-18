/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/18 20:44:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(int argc, char **argv)
{
	t_data	data;

	get_lines(check_args(argc, argv), argv[1], &data, &data.map);
	found_error((void **) data.dot);
	get_each_point(&data);
	win_initialization(&data);
	handle_hooks(&data);
	mlx_loop(data.mlx_ptr);
}
