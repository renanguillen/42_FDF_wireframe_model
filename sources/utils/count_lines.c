/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:17:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/07 20:59:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"

int	count_lines(char *argv)
{
	int		fd;
	char	c;
	int		lines;

	lines = 0;
	fd = open(argv, O_RDONLY);
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
