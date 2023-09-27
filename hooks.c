/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/27 03:23:17 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	destroy_and_free(t_fractals *fractal)
{
	mlx_destroy_image(fractal->img.mlx_ptr, fractal->img.img);
	mlx_destroy_window(fractal->img.mlx_ptr, fractal->img.mlx_win);
	mlx_destroy_display(fractal->img.mlx_ptr); 
	free(fractal->img.mlx_ptr);
	exit(0);
}

int	moves(int keysym, t_fractals *fractal)
{
	fractal->med_x = (fractal->max_x - fractal->min_x);
    fractal->med_y = (fractal->max_y - fractal->min_y);
	if (keysym == KEY_UP)
	{
		fractal->max_y -= fractal->med_y * 0.05;
		fractal->min_y -= fractal->med_y * 0.05;
	}
	else if (keysym == KEY_DOWN)
	{
		fractal->max_y += fractal->med_y * 0.05;
		fractal->min_y += fractal->med_y * 0.05;
	}
	else if (keysym == KEY_LEFT)
	{
		fractal->max_x -= fractal->med_x * 0.05;
		fractal->min_x -= fractal->med_x * 0.05;
	}
	else if (keysym == KEY_RIGHT)
	{
		fractal->max_x += fractal->med_x * 0.05;
		fractal->min_x += fractal->med_x * 0.05;
	}
	return (0);
}

int	change_julia(int keysym, t_fractals *fractal)
{
	if (keysym == KEY_Z)
		fractal->julia_complex.real += 0.05;
	else if (keysym == KEY_S)
		fractal->julia_complex.real -= 0.05;
	else if (keysym == KEY_Q)
		fractal->julia_complex.imag -= 0.05;
	else if (keysym == KEY_D)
		fractal->julia_complex.imag += 0.05;
	// if (fractal->fract == julia_iterations)
	// 	printf("Julia set : %f + %fi\n", fractal->julia_complex.real, fractal->julia_complex.imag);
	return (0);
}

int	handle_input(int keysym, t_fractals *fractal)
{
	if (keysym == KEY_ESC)
	{
		destroy_and_free(fractal);
		exit(0);
	}
	moves(keysym, fractal);
	change_julia(keysym, fractal);
	draw_fractal(fractal);
	return (0);
}

int	handle_mouse(int event, int x, int y, t_fractals *fractal)
{
	(void)x;
	(void)y;
	fractal->med_x = (fractal->max_x - fractal->min_x);
    fractal->med_y = (fractal->max_y - fractal->min_y);
	if (event == MOUSE_UP)
	{
		fractal->max_x += fractal->med_x * 0.2;
		fractal->min_x -= fractal->med_x * 0.2;
		fractal->max_y += fractal->med_y * 0.2;
		fractal->min_y -= fractal->med_y * 0.2;
	}
	else if (event == MOUSE_DOWN)
	{
		fractal->max_x -= fractal->med_x * 0.2;
		fractal->min_x += fractal->med_x * 0.2;
		fractal->max_y -= fractal->med_y * 0.2;
		fractal->min_y += fractal->med_y * 0.2;
	}
	draw_fractal(fractal);
	// if (fractal->move == false)
	// {
	// 	ft_free_cache(fractal->cache, WIDTH);
	// 	create_cache(WIDTH, HEIGHT);
	// 	fractal->move = true;
	// }
	// else
	// 	update_cache(fractal);
	return (0);
}

// int handle_mouse(int event, t_fractal *fractal)