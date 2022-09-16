/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:07:17 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 23:18:14 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	handle_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &draw_image, data);
	mlx_hook(data->win_ptr, 17, 0, &handle_x_button, data);
	mlx_key_hook(data->win_ptr, &handle_keypress, data);
}
