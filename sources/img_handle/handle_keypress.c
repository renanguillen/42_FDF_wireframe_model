/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:54:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/15 23:11:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

static int	handle_arrows(int key, t_data *data)
{
	if (key == XK_Left)
	{
		data->travelx -= 30;
		printf("%d\n", data->travelx);
	}
	else if (key == XK_Right)
	{
		data->travelx += 30;
		printf("%d\n", data->travelx);
	}
	else if (key == XK_Up)
	{
		data->travely -= 30;
		printf("%d\n", data->travely);
	}
	else if (key == XK_Down)
	{
		data->travely += 30;
		printf("%d\n", data->travely);
	}
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		free_data(data);
		exit (0);
	}
	else
		handle_arrows(key, data);
	return (0);
}
