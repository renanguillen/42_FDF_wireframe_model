/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:52:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/23 21:33:39 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	get_scale(t_data *data)
{
	data->scalex = (WINDOW_WIDTH / 2) - (data->diag * (2000 / data->area));
	data->scaley = (WINDOW_HEIGHT / 2);
}
