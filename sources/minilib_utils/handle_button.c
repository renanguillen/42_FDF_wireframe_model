/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:54:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/12 21:31:17 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

int	handle_button(int keypress, t_data *data)
{
	
	if (keypress == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (1);
	}
	else if (keypress == XK_Left)
	{
		data->travelx -= 4;
		printf("%d\n", keypress);
	}
	else if (keypress == XK_Right)
	{
		data->travelx += 4;
		printf("%d\n", data->travelx);
	}
	else if (keypress == XK_Up)
	{
		data->travely -= 4;
		printf("%d\n", data->travely);
	}
	else if (keypress == XK_Down)
	{
		data->travely += 4;
		printf("%d\n", data->travely);
	}
	return (0);
}
