/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:41:30 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/27 18:26:34 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int pick_fractal(int argc, char **argv, t_fractals *fractal)
{   
    if (is_julia(argv))
	{
		fractal->fract = julia_iterations;
		if (argc == 4 && (ft_isdigits(argv[2]) && ft_isdigits(argv[3])))
		{
			fractal->julia_complex.real = ft_atod(argv[2]);
			fractal->julia_complex.imag = ft_atod(argv[3]);
		}
		else if (argc == 2)
		{
			fractal->julia_complex.real = -1;
			fractal->julia_complex.imag = 0;
		}
		else
			ft_error_arg();
	}
    if (is_mandelbrot(argv))
	{
		if (argc != 2)
			ft_error_arg();
        else 
			fractal->fract = mandelbrot_iterations;
	}
    return (0);
}

int julia_iterations(t_fractals *fractal)
{
    t_complex   dot;
    double      temp;

    dot.real = fractal->x;
    dot.imag = fractal->y;
    fractal->iterations = 0;
    while (fractal->iterations < fractal->max_iterations)
    {
        temp = dot.real;
        dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + fractal->julia_complex.real;
		dot.imag = 2 * temp * dot.imag + fractal->julia_complex.imag;
        if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
            break; 
        fractal->iterations++;
    }
    return (fractal->iterations);
}

int mandelbrot_iterations(t_fractals *fractal)
{
    t_complex   dot;
    double      temp;

    dot.real = 0;
    dot.imag = 0;
    fractal->iterations = 0;
    while (fractal->iterations < fractal->max_iterations)
    {
        temp = dot.real;
        dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + fractal->x;
		dot.imag = 2 * (temp * dot.imag) + fractal->y;
        if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
            break; 
        fractal->iterations++;
    }
    return (fractal->iterations);
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
    rgb[0] = sin(0.11 * fractal->iterations + fractal->color_B) * 125 + 126;
	rgb[1] = sin(0.11 * fractal->iterations + fractal->color_G) * 125 + 126;
	rgb[2] = sin(0.11 * fractal->iterations + fractal->color_R) * 125 + 126;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
