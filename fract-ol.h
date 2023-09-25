/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:39 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/21 20:16:22 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "libft/libft.h"

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5

# define WIDTH 1200
# define HEIGHT 800
# define ZOOM_FACTOR 1.15

typedef struct s_complex {
    double  real;
    double  imag;
} t_complex;

typedef struct s_img {
    void    *img;
    char    *addr;
    void    *mlx_ptr;
    void    *mlx_win;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_fractals {
    int                 iterations;
    int                 max_iterations;
    double              x;
    double              y;
    double              min_x;
    double              max_x;
    double              min_y;
    double              max_y;
    double              med_x;
    double              med_y;
    struct s_img        img;
    struct s_complex    julia_complex;
    int                 **cache;
    int                (*fract)(struct s_fractals *fractal);
} t_fractals;


int     julia_iterations(t_fractals *fractal);
int     mandelbrot_iterations(t_fractals *fractal);
int     pick_fractal(int argc, char **argv, t_fractals *fractal);
void    draw_fractal(t_fractals *fractal);
int     ft_color(t_fractals *fractal);
int     handle_input(int keysym, t_fractals *fractal);
int     handle_mouse(int event, int x, int y, t_fractals *fractal);
int     handle_no_event();
int     destroy_and_free(t_fractals *fractal);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
int     is_julia(char **argv);
int     is_mandelbrot(char **argv);
void	ft_error(void);
void	ft_error_arg(void);
int	    ft_isdigits(char *str);

int         **create_cache(int width, int height);
int         ft_isincache(t_fractals *fractal, int x, int y);
int         ft_getorcalculate(t_fractals *fractal, int x, int y);
void        ft_free_cache(int **cache, int width);
#endif