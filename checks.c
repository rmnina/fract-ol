/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:54:53 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/21 16:34:56 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_error_arg(void)
{
	ft_putstr_fd("Error arguments.\nusage:  Julia fractals \
	\t fract-ol [\"julia\"] [real] [imag] (real = -1 and imag = 0 by default)\n\tMandelbrot fractal \t fract-ol [\"mandelbrot\"]\n", 2);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
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

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	res;
	double	div;

	i = 0;
	res = 0;
	sign = 1;
	div = 10;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (res * sign);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0') / div;
		div *= 10;
		i++;
	}
	printf("res atod = %f\n", res * sign);
	return (res * sign);
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


int pick_fractal(int argc, char **argv, t_fractals *fractal)
{   
    if (is_julia(argv))
	{
		fractal->fract = julia_iterations;
		if (argc == 4 && (ft_isdigits(argv[2]) && ft_isdigits(argv[3])))
		{
			fractal->julia_complex.real = ft_atod(argv[2]);
			fractal->julia_complex.imag = ft_atod(argv[3]);
		}
		else if (argc == 2)
		{
			fractal->julia_complex.real = -1;
			fractal->julia_complex.imag = 0;
		}
		else
			ft_error_arg();
	}
    if (is_mandelbrot(argv))
	{
		if (argc != 2)
			ft_error_arg();
        else 
			fractal->fract = mandelbrot_iterations;
	}
    return (0);
}

