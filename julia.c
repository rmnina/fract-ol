/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:40 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/16 17:30:02 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int julia_iterations(double x, double y, int max_iterations, t_complex c)
{
    t_complex   dot;
    double      temp;
    int         iterations;

    dot.real = x;
    dot.imag = y;
    iterations = 0;
    while (iterations < max_iterations)
    {
        temp = dot.real;
        dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + c.real;
		dot.imag = 2 * temp * dot.imag + c.imag;
        if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
            break; 
        iterations++;
    }
    return iterations;
}

void draw_julia_set(t_data *data, int max_iterations, t_complex c)
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
            data->complex.real = data->min_x + (data->max_x - data->min_x) * x / (WIDTH - 1);
            data->complex.imag = data->min_y + (data->max_y - data->min_y) * y / (HEIGHT - 1);
            iterations = julia_iterations(data->complex.real, data->complex.imag, max_iterations, c);
            if (iterations == max_iterations)
                color = 0x00111111;
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
    t_complex   complex;

    complex.imag = 0;
    complex.real = -1;
    img.min_x = -2.0;
    img.max_x = 2.0;
    img.min_y = -1.5;
    img.max_y = 1.5;
    img.mlx_ptr = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "Fractale de Julia");
    img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw_julia_set(&img, 100, complex);
    mlx_loop_hook(img.mlx_ptr, &handle_no_event, &img);
    mlx_key_hook(img.mlx_win, &handle_input, &img);
    mlx_loop(img.mlx_ptr);
    free(img.mlx_ptr);
    return 0;
}


//Zn+1 = (Zn)² + C (JULIA : en fonction de C ; MANDELBROT : en fonction de Z0)