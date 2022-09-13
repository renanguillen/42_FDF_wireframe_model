/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:54:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/13 23:49:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

static int	handle_arrows(int key, t_data *data)
{
	if (key == XK_Left)
	{
		data->travelx -= 4;
		printf("%d\n", data->travelx);
	}
	else if (key == XK_Right)
	{
		data->travelx += 4;
		printf("%d\n", data->travelx);
	}
	else if (key == XK_Up)
	{
		data->travely -= 4;
		printf("%d\n", data->travely);
	}
	else if (key == XK_Down)
	{
		data->travely += 4;
		printf("%d\n", data->travely);
	}
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (1);
	}
	else
		handle_arrows(key, data);
	return (0);
}
