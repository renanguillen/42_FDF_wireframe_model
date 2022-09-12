/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:54:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/12 20:07:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

int	handle_button(int keypress, t_data *data)
{
	if (keypress == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (1);
	}
	else if (keypress == 65361)
	{
		data->travelx -= 4;
		printf("%d\n", data->travelx);
	}
	else if (keypress == 65363)
	{
		data->travelx += 4;
		printf("%d\n", data->travelx);
	}
	else if (keypress == 65362)
	{
		data->travely -= 4;
		printf("%d\n", data->travely);
	}
	else if (keypress == 65364)
	{
		data->travely += 4;
		printf("%d\n", data->travely);
	}
	return (0);
}
