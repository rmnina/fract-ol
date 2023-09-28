/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/28 19:00:35 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		fractal->julia_complex.real += 0.005;
	else if (keysym == KEY_S)
		fractal->julia_complex.real -= 0.005;
	else if (keysym == KEY_Q)
		fractal->julia_complex.imag -= 0.005;
	else if (keysym == KEY_D)
		fractal->julia_complex.imag += 0.005;
	return (0);
}

int	handle_input(int keysym, t_fractals *fractal)
{
	if (keysym == KEY_ESC)
	{
		destroy_and_free(fractal);
		exit(0);
	}
	else if (keysym == PAD_9 && fractal->max_iterations < 800)
		fractal->max_iterations += 50;
	else if (keysym == PAD_6 && fractal->max_iterations > 50)
		fractal->max_iterations -= 50;
	moves(keysym, fractal);
	change_julia(keysym, fractal);
	color_set(keysym, fractal);
	draw_fractal(fractal);
	return (0);
}

int	handle_mouse(int event, int x, int y, t_fractals *fractal)
{
	fractal->med_x = (fractal->max_x - fractal->min_x);
	fractal->med_y = (fractal->max_y - fractal->min_y);
	fractal->center_x = fractal->min_x + ((double)x / WIDTH) * fractal->med_x;
	fractal->center_y = fractal->min_y + ((double)y / HEIGHT) * fractal->med_y;
	if (event == MOUSE_DOWN)
		mouse_down(fractal, x, y);
	else if (event == MOUSE_UP)
		mouse_up(fractal, x, y);
	draw_fractal(fractal);
	return (0);
}
