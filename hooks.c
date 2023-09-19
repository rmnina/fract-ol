/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/19 21:18:42 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int handle_no_event(t_img *img)
{
    // draw_julia_set(img, 100, c);
    return (0);
}


int handle_input(int keysym, t_fractals *fractal)
{
    // printf("code = %p\n", fractal->fract);
    // if (keysym == KEY_ESC)
    //     mlx_destroy_window(img->mlx_ptr, img->mlx_win);
    t_img *img;
    
    if (keysym == KEY_UP)
	{
		fractal->max_y += fractal->med_y * 0.1;
        fractal->min_y += fractal->med_y * 0.1;
	}
	else if (keysym == KEY_DOWN)
	{
        fractal->max_y -= fractal->med_y * 0.1;
        fractal->min_y -= fractal->med_y * 0.1;
	}
    else if (keysym == KEY_LEFT)
	{
        fractal->max_x += fractal->med_x * 0.1;
        fractal->min_x += fractal->med_x * 0.1;
	}
    else if (keysym == KEY_RIGHT)
	{
        fractal->max_x -= fractal->med_x * 0.1;
        fractal->min_x -= fractal->med_x * 0.1;
	}
    draw_fractal(img, fractal);
    return (0);
}

// int handle_mouse(int event, t_fractal *fractal)