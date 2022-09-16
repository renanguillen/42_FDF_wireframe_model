/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:51:55 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/16 21:08:54 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct t_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	color0;
	int	color1;
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
	int	hei;
}	t_win;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_dot;

typedef struct s_map
{
	int		rows;
	int		cols;
	float	diagonal;
	float	scalei;
	float	scalej;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_win	win;
	t_map	map;
	t_dot	**dot;
	int		cur_img;
	int		travelx;
	int		travely;
	char	**lines;
	char	**split;
}	t_data;

#endif