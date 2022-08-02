/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/02 19:15:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

// int	handle_input(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	data;

// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
// 			"My first window!");
// 	if (data.win_ptr == NULL)
// 	{
// 		free(data.win_ptr);
// 		return (MLX_ERROR);
// 	}

// 	/* Setup hooks */ 
// 	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
// 	mlx_key_hook(data.win_ptr, &handle_input, &data);

// 	mlx_loop(data.mlx_ptr);

// 	/* we will exit the loop if there's no window left, and execute this code */
// 	mlx_destroy_display(data.mlx_ptr);
// 	free(data.mlx_ptr);
// }
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);

	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	/* Setup hooks */ 
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); /* ADDED */
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}