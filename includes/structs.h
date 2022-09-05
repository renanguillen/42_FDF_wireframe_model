/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:51:55 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/06 00:30:12 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_line
{
	int	x;
	int	y;
	int	xend;
	int	yend;
	int	dx;
	int	dy;
}	t_line;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_line	line;
}	t_img;

typedef struct s_win
{
	int	wid;
	int hei;
}	t_win;

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_dot;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_win	win;
	t_dot	**dot;
	int		cur_img;
	float	rows;
	float	cols;
	float	diagonal;
	float	scalei;
	float	scalej;
	char	**lines;
	char	**split;
}	t_data;

#endif