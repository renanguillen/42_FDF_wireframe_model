/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:17:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/11 15:48:18 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	count_lines(char *argv)
{
	int		fd;
	char	c;
	int		lines;

	lines = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n' || c == 0)
			lines++;
	}
	return (lines);
}
