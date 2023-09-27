/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:54:53 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/27 18:02:49 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(1);
}

void	ft_error_arg(void)
{
	ft_putstr_fd("Error arguments.\nusage:  Julia fractals \
	\t fract-ol [\"julia\"] [real] [imag] (real = -1 and imag = 0 by default)\n\tMandelbrot fractal \t fract-ol [\"mandelbrot\"]\n", 2);
	exit(1);
}

int	ft_isdigits(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (i == 0 && str[i] != '-') && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int is_julia(char **argv)
{
    if (argv [1] && (ft_strncmp(argv[1], "Julia", 6) == 0 || ft_strncmp(argv[1], "julia", 5) == 0))
		return (1);
    return (0);
}

int is_mandelbrot(char **argv)
{
    if (argv[1] && (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 || ft_strncmp(argv[1], "mandelbrot", 10) == 0))
        return (1);
    return (0);
}
