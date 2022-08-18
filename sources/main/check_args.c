/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:18:26 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/18 16:18:01 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
		ft_putstr_fd("File could not be opened\n", 2);
		exit(1);
	}
	return (i);
}
