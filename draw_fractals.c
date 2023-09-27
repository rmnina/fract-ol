/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:41:30 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/28 00:59:25 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int pick_fractal(int argc, char **argv, t_fractals *fractal)
{   
    if (is_julia(argv))
	{
		fractal->fract = julia_iterations;
        init_julia_val(argc, argv, fractal);
	}
    if (is_mandelbrot(argv))
	{
		if (argc == 2)
			fractal->fract = mandelbrot_iterations;
	}
	if (is_burningship(argv))
	{
		if (argc == 2)
			fractal->fract = burning_ship_iterations;
	}
	if (is_mandelbar(argv))
	{
		if (argc == 2)
			fractal->fract = mandelbar_iterations;
	}
    return (0);
}

int draw_fractal(t_fractals *fractal)
{
    int     x;
    int     y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            fractal->x = fractal->min_x + (fractal->max_x - fractal->min_x) * x / (WIDTH);
			fractal->y = fractal->min_y + (fractal->max_y - fractal->min_y) * y / (HEIGHT);
			fractal->fract(fractal);
            my_mlx_pixel_put(&fractal->img, x, y, ft_color(fractal));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->img.mlx_ptr, fractal->img.mlx_win, fractal->img.img, fractal->min_x, fractal->min_y);
	return (0);
}

int ft_color(t_fractals *fractal)
{
    int rgb[3];
    
    if (fractal->iterations == fractal->max_iterations)
        return (0x00111111);
    rgb[0] = sin(0.2 * fractal->iterations + fractal->color_RB) * 125 + 126;
	rgb[1] = sin(0.2 * fractal->iterations + fractal->color_GPi) * 125 + 126;
	rgb[2] = sin(0.2 * fractal->iterations + fractal->color_YPu) * 125 + 126;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
