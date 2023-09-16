/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:50 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/16 16:14:22 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int mandelbrot_iterations(double x, double y, int max_iterations)
{
    t_complex   dot;
    double      temp;
    int         iterations;

    dot.real = 0;
    dot.imag = 0;
    iterations = 0;
    while (iterations < max_iterations)
    {
        temp = dot.real;
        dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + x;
		dot.imag = 2 * (temp * dot.imag) + y;
        if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
            break; 
        iterations++;
    }
    return iterations;
}

void draw_mandelbrot_set(t_data *data, int max_iterations)
{
    int     iterations;
    int     color;
    int     x;
    int     y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            data->complex.real = (WIDTH / 200) * (-1) + (x * 0.005);
            data->complex.imag = (HEIGHT / 150) - (y * 0.005);
            iterations = mandelbrot_iterations(data->complex.real, data->complex.imag, max_iterations);
            if (iterations == max_iterations)
                color = 0x000001111;
            else
                color = ft_rainbow(iterations);
            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
}

int main()
{
    t_data      img;

    img.mlx_ptr = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx_ptr, HEIGHT, WIDTH, "Fractale de Mandelbrot");
    img.img = mlx_new_image(img.mlx_ptr, HEIGHT, WIDTH);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw_mandelbrot_set(&img, 100);
    mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.img, 0, 0);
    mlx_loop_hook(img.mlx_ptr, &handle_no_event, &img);
    mlx_key_hook(img.mlx_win, &handle_input, &img);
    mlx_loop(img.mlx_ptr);
    free(img.mlx_ptr);
    return 0;
}