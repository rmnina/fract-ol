/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:48:41 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/16 17:44:03 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define MOUSE_UP 5
# define MOUSE_DOWN 4

# define WIDTH 1200
# define HEIGHT 800

typedef struct s_complex {
    double  real;
    double  imag;
} t_complex;

typedef struct s_data {
    void                *img;
    char                *addr;
    void                *mlx_ptr;
    void                *mlx_win;
    int                 bits_per_pixel;
    int                 line_length;
    int                 endian;
    double              min_x;
    double              max_x;
    double              min_y;
    double              max_y;
    struct s_complex    complex;
} t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     ft_rainbow(int iterations);
int     handle_input(int keysym, t_data *data, int max_iterations, t_complex c);
int     handle_no_event(t_data *img, t_complex c);
int     handle_moves(int keysym, t_data *data);
int     handle_up_down_moves(int keysym, t_data *data);
int     handle_left_right_moves(int keysym, t_data *data);
void    draw_julia_set(t_data *data, int max_iterations, t_complex c);

#endif