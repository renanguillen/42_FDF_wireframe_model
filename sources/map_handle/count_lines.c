/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:17:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/16 21:24:22 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

int	count_lines(char *filename)
{
	int		fd;
	char	c;
	int		lines;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("File could not be opened\n", 2);
		exit(1);
	}
	while (read(fd, &c, 1))
	{
		if (c == '\n' || c == 0)
			lines++;
	}
	return (lines);
}
