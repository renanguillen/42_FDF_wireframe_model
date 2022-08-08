/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/08 20:26:12 by coder            ###   ########.fr       */
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

void found_error(void **pointer)
{
	if (!pointer)
	{
		ft_putstr_fd("Something went wrong\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		row_count;
	char	**lines;
	int		i;
	int		j;
	char	**split;
	char	**split2;
	int		col_count;
	t_dot	**dot;

	i = 0;
	fd = check_args(argc, argv);
	row_count = count_lines(argv[1]);
	lines = malloc(sizeof (char *) * (row_count + 1));
	found_error ((void **)lines);
	while (i < row_count)
		lines[i++] = get_next_line(fd);
	lines[i] = NULL;
	i = 0;
	split = ft_split(lines[i], ' ');
	col_count = ft_splitlen(split);
	ft_matrixfree((void **)split);
	dot = malloc(sizeof (t_dot *) * row_count);
	found_error ((void **)dot);
	while (lines[i])
	{
		dot[i] = malloc(sizeof (t_dot) * col_count);
		found_error((void **) &dot[i]);
		split = ft_split(lines[i], ' ');
		j = 0;
		while (j < col_count)
		{
			if (ft_strchr(split[j], ','))
			{
				split2 = ft_split(split[j], ',');
				dot[i][j].value = ft_atoi(split2[0]);
				dot[i][j].color = split2[1];
				ft_matrixfree((void **)split2);
			}
			else
			{
				dot[i][j].value = ft_atoi(split[j]);
				dot[i][j].color = "0xFFFFFF";
			}
		}
		ft_matrixfree(split);
		i++;
	}
	return (0);
}