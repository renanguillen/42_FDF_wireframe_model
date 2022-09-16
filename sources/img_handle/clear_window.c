/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:48:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 22:49:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

void	clear_window(t_img *img)
{
	int		i;
	int		j;
	int		k;
	char	*pixel;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			k = img->bpp - 8;
			pixel = img->addr + (i * img->line_len + j * (img->bpp / 8));
			while (k >= 0)
			{
				if (img->endian != 0)
					*pixel++ = (0 >> k) & 0xFF;
				else
					*pixel++ = (0 >> (img->bpp - 8 - k)) & 0xFF;
				k -= 8;
			}
			j++;
		}
		i++;
	}
}
