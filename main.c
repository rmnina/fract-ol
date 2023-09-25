/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:34:29 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/21 19:42:15 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    init_fract(int argc, char **argv, t_fractals *fractal)
{
    pick_fractal(argc, argv, fractal);
    fractal->min_x = -2.0;
    fractal->max_x = 2.0;
    fractal->min_y = -1.5;
    fractal->max_y = 1.5;
    fractal->med_x = (fractal->max_x - fractal->min_x);
    fractal->med_y = (fractal->max_y - fractal->min_y);
    fractal->max_iterations = 100;
    fractal->cache = create_cache(WIDTH, HEIGHT);
}

void    init_img(t_fractals *fractal)
{
    fractal->img.mlx_ptr = mlx_init();
    if (fractal->img.mlx_ptr == NULL)
        ft_error();
    fractal->img.mlx_win = mlx_new_window(fractal->img.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
    if (fractal->img.mlx_win == NULL)
    {
        free(fractal->img.mlx_ptr);
        ft_error();
    }
    fractal->img.img = mlx_new_image(fractal->img.mlx_ptr, WIDTH, HEIGHT);
    {
        if (fractal->img.img == NULL)
        {
            free(fractal->img.mlx_win);
            free(fractal->img.mlx_ptr);
            ft_error();
        }
    }
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
}

int main(int argc, char **argv)
{
    t_fractals  fractal;
    
    if (is_julia(argv) && (argc != 2 && argc != 4))
        ft_error_arg();
    else if (is_mandelbrot(argv) && (argc != 2))
        ft_error_arg();
    if (!is_julia(argv) && !is_mandelbrot(argv))
        ft_error_arg();
    else
    {
        init_fract(argc, argv, &fractal);
        init_img(&fractal);
        mlx_mouse_hook(fractal.img.mlx_win, &handle_mouse, &fractal);
        mlx_key_hook(fractal.img.mlx_win, &handle_input, &fractal);
        mlx_hook(fractal.img.mlx_win, 17, 0, &destroy_and_free, &fractal);
        mlx_loop_hook(fractal.img.mlx_ptr, &handle_no_event, &fractal);
        draw_fractal(&fractal);
        mlx_loop(fractal.img.mlx_ptr);
    }
    return (0);
}