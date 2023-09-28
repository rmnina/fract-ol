/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:54:53 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/28 19:00:48 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_arg(void)
{
	ft_putstr_fd("Error arguments.\nusage:  Julia fractals \
	\t\t fract-ol [\"julia\"] (optionnal : add [real] [imag])\n\tMandelbrot fractal \
	\t fract-ol [\"mandelbrot\"]\n\tBurning Ship fractal \
	\t fract-ol [\"burningship\"]\n\tMandelbar Celtic fractal \
	 fract-ol [\"mandelbar\"]\n", 2);
	exit(1);
}

int	is_julia(char **argv)
{
	if (argv [1] && (ft_strncmp(argv[1], "Julia", 6) == 0 || \
	ft_strncmp(argv[1], "julia", 5) == 0))
		return (1);
	return (0);
}

int	is_mandelbrot(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 || \
	ft_strncmp(argv[1], "mandelbrot", 10) == 0))
		return (1);
	return (0);
}

int	is_mandelbar(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "Mandelbar", 10) == 0 || \
	ft_strncmp(argv[1], "mandelbar", 10) == 0))
		return (1);
	return (0);
}

int	is_burningship(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "Burningship", 12) == 0 || \
	ft_strncmp(argv[1], "burningship", 12) == 0))
		return (1);
	return (0);
}
