/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/05 16:05:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid syntax\n", 2);
		exit (1);
	}
	else
	{
		i = ft_strlen(argv[1]) - 1;
		if (argv[1][i] != 'f' || argv[1][i - 1] != 'd' || argv[1][i - 2] != 'f'
			|| argv[1][i - 3] != '.')
			{
				ft_putstr_fd("Invalid file type\n", 2);
				exit (1);
			}
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
	{
		ft_putstr_fd("Something went wrong\n", 2);
		exit(1);
	}
	return (i);
}

// int	count_lines(int fd)
// {
	
// }

int	main(int argc, char **argv)
{
	t_data	data;
	t_dot	*dot;
	int fd;
	// int lines;
	
	fd = check_args(argc, argv);
	// lines = count_lines(fd);
}