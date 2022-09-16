/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:49:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 21:02:25 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	put_a_pixel(t_img *img, t_line *line)
{
	char	*pixel;
	int		i;

	if (line->x0 < 0 || line->x0 > WINDOW_WIDTH
		|| line->y0 < 0 || line->y0 > WINDOW_HEIGHT)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (line->y0 * img->line_len + line->x0 * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (line->color0 >> i) & 0xFF;
		else
			*pixel++ = (line->color0 >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
