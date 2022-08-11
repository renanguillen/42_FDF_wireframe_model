/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:52:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/11 21:18:39 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	get_scale(t_data *data)
{
	data->win.wid = (data->cols * data->constant) + 100;
	data->win.hei = (data->rows * data->constant) + 100;
}
