/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:52:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/24 19:31:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	get_scale(t_data *data)
{
	data->scalex = (WINDOW_WIDTH / 2) - (data->diag * (1000 / data->area));
	data->scaley = (WINDOW_HEIGHT / 2);
}
