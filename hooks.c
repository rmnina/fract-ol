/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/16 17:45:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int handle_no_event(t_data *img, t_complex c)
{
    // draw_julia_set(img, 100, c);
    mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->img, img->min_x, img->min_y);
    return (0);
}


int handle_input(int keysym, t_data *data, int max_iterations, t_complex c)
{
    printf("code = %d\n", keysym);
    if (keysym == KEY_ESC)
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
    if (keysym == KEY_UP)
        data->max_y += 1;
    if (keysym == KEY_DOWN)
        data->min_y -= 0.1;
    if (keysym == KEY_LEFT)
        data->max_x += 0.1;
    if (keysym == KEY_RIGHT)
        data->min_x -= 0.1;
    return (0);
}

// int handle_mouse(int event, t_data *data)