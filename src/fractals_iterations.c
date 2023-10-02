/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_iterations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:21:01 by jdufour           #+#    #+#             */
/*   Updated: 2023/10/02 12:36:22 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = fractal->x;
	dot.imag = fractal->y;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + \
		fractal->julia_complex.real;
		dot.imag = 2 * temp * dot.imag + fractal->julia_complex.imag;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}

int	mandelbrot_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = 0;
	dot.imag = 0;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + fractal->x;
		dot.imag = 2 * (temp * dot.imag) + fractal->y;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}

int	mandelbar_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = 0;
	dot.imag = 0;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = fabs(pow(dot.real, 2) - pow(dot.imag, 2)) + fractal->x;
		dot.imag = -2 * temp * dot.imag + fractal->y;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}

int	burning_ship_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = 0;
	dot.imag = 0;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = fabs(pow(dot.real, 2) - pow(dot.imag, 2)) + fractal->x;
		dot.imag = 2 * fabs(temp * dot.imag) + fractal->y;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}
