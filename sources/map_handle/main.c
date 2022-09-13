/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/13 23:50:39 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

static int	check_mlx_pointer(t_data *data)
{
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	return (0);
}

static int	check_mlx_window(t_data *data)
{
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	get_lines(argc, argv, &data);
	found_error((void **) data.dot);
	data.travelx = 0;
	data.travely = 0;
	write_matrix(&data);
	data.mlx_ptr = mlx_init();
	check_mlx_pointer(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Bibbidi Bobbidi Boo");
	check_mlx_window(&data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.img.mlx_img, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &draw_image, &data);
	mlx_hook(data.win_ptr, 17, 0, &handle_x_button, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
