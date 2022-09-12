/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:49:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/12 19:19:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	put_a_pixel(t_img *img)
{
	char	*pixel;
	int		i;

	if (img->x0 < 0 || img->x0 > WINDOW_WIDTH
		|| img->y0 < 0 || img->y0 > WINDOW_HEIGHT)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (img->y0 * img->line_len + img->x0 * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (img->color >> i) & 0xFF;
		else
			*pixel++ = (img->color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
