/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:54:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/22 20:40:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
	return (0);
}
