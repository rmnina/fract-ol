/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:39 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/27 18:29:41 by jdufour          ###   ########.fr       */
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
# include <stdbool.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define KEY_Z 122
# define KEY_S 115
# define KEY_Q 113
# define KEY_D 100

# define PAD_1 65436
# define PAD_2 65433
# define PAD_3 65435
# define PAD_4 65430
# define PAD_5 65437
# define PAD_6 65432
# define PAD_7 65429
# define PAD_8 65431
# define PAD_9 65434
# define PAD_0 65438

# define WIDTH 1500
# define HEIGHT 1000
# define ZOOM_FACTOR 1.15

typedef struct s_complex {
	double	real;
	double	imag;
} 			t_complex;

typedef struct s_img {
	void	*img;
	char	*addr;
	void	*mlx_ptr;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractals {
	int					iterations;
	int					max_iterations;
	int					mouse_pos;
	int					color_B;
	int					color_G;
	int					color_R;
	double				x;
	double				y;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				med_x;
	double				med_y;
	bool				move;	
	struct s_img		img;
	struct s_complex	julia_complex;
	int					**cache;
	int					(*fract)(struct s_fractals *fractal);
}						t_fractals;

//	Fractals
int			julia_iterations(t_fractals *fractal);
int			mandelbrot_iterations(t_fractals *fractal);
int			pick_fractal(int argc, char **argv, t_fractals *fractal);
int			draw_fractal(t_fractals *fractal);
int			ft_color(t_fractals *fractal);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			is_julia(char **argv);
int			is_mandelbrot(char **argv);

//	Events
int			handle_input(int keysym, t_fractals *fractal);
int			handle_mouse(int event, int x, int y, t_fractals *fractal);
int			handle_no_event();
int			destroy_and_free(t_fractals *fractal);

//	Checks
void		ft_error(void);
void		ft_error_arg(void);
int			ft_isdigits(char *str);

// Opti
int			**create_cache(int width, int height);
int			ft_isincache(t_fractals *fractal, int x, int y);
int			ft_getorcalculate(t_fractals *fractal, int x, int y);
void		update_cache(t_fractals *fractal);
void		update_cache_after_move(t_fractals *fractal);
void		ft_free_cache(int **cache, int width);

void		ft_fractol_man(void);
int			color_set(int keysym, t_fractals *fractal);

#endif