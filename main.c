/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:34:29 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/19 21:17:00 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    init_fract(char **argv, t_fractals *fractal)
{
    printf("yo\n");
    pick_fractal(argv, fractal);
    printf("adresse %p\n", fractal->fract);
    fractal->julia_complex.imag = 0;
    fractal->julia_complex.real = -1;
    fractal->min_x = -2.0;
    fractal->max_x = 2.0;
    fractal->min_y = -1.5;
    fractal->max_y = 1.5;
    fractal->med_x = (fractal->max_x - fractal->min_x);
    fractal->med_y = (fractal->max_y - fractal->min_y);
    fractal->max_iterations = 100;
}

void    init_img(t_img *img)
{
    img->mlx_ptr = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
    img->img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int main(int argc, char **argv)
{
    t_img       img;
    t_fractals  fractal;
    t_complex   complex;

    if (argc != 2)
        return (printf("error argv\n"), 1);
    init_fract(argv, &fractal);
    init_img(&img);
    mlx_loop_hook(img.mlx_ptr, &handle_no_event, &fractal);
    mlx_key_hook(img.mlx_win, &handle_input, &fractal);
    draw_fractal(&img, &fractal);
    mlx_loop(img.mlx_ptr);
    free(img.mlx_ptr);
    return 0;
}