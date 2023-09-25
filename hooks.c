/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/21 19:49:07 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int handle_no_event()
{
    // draw_julia_set(img, 100, c);
    return (0);
}

int destroy_and_free(t_fractals *fractal)
{
    mlx_destroy_image(fractal->img.mlx_ptr, fractal->img.img);
    mlx_destroy_window(fractal->img.mlx_ptr, fractal->img.mlx_win);
    mlx_destroy_display(fractal->img.mlx_ptr); 
    free(fractal->img.mlx_ptr);
    exit(0);
}

int moves(int keysym, t_fractals *fractal)
{
    if (keysym == KEY_UP)
	{
		fractal->max_y -= fractal->med_y;
        fractal->min_y -= fractal->med_y;
	}
	else if (keysym == KEY_DOWN)
	{
        fractal->max_y += fractal->med_y;
        fractal->min_y += fractal->med_y;
	}
    else if (keysym == KEY_LEFT)
	{
        fractal->max_x -= fractal->med_x;
        fractal->min_x -= fractal->med_x;
	}
    else if (keysym == KEY_RIGHT)
	{
        fractal->max_x += fractal->med_x;
        fractal->min_x += fractal->med_x;
	}
    return (0);
}

int handle_input(int keysym, t_fractals *fractal)
{
    if (keysym == KEY_ESC)
    {
        destroy_and_free(fractal);
        exit(0);
    }
    moves(keysym, fractal);
    draw_fractal(fractal);
    return (0);
}

int handle_mouse(int event, int x, int y, t_fractals *fractal)
{
    (void)x;
    (void)y;
    if (event == MOUSE_UP)
    {
        fractal->max_x *= ZOOM_FACTOR;
        fractal->min_x *= ZOOM_FACTOR;
        fractal->max_y *= ZOOM_FACTOR;
        fractal->min_y *= ZOOM_FACTOR;
    }
    else if (event == MOUSE_DOWN)
    {
        fractal->max_x *= 1 / ZOOM_FACTOR;
        fractal->min_x *= 1 / ZOOM_FACTOR;
        fractal->max_y *= 1 / ZOOM_FACTOR;
        fractal->min_y *= 1 / ZOOM_FACTOR;
    }
    draw_fractal(fractal);
    return (0);
}

// int handle_mouse(int event, t_fractal *fractal)