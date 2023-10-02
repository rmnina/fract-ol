/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:06:15 by jdufour           #+#    #+#             */
/*   Updated: 2023/10/02 14:25:17 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_fractol_man(void)
{
	ft_printf(" \n\t---👾👾😏--- Welcome on my fract-ol ---😏👾👾--- \n\tYou can use the following options :\n\
	⬆ ➡  Move the camera with the directional arrows\n\t🖱 🖱  Zoom in and out with the mouse scroller\n\
	🌌🎆 Change the Julia equation :\n\t\t- W to raise and S to lower the real part\n\
	\t- D to raise and A tower the imaginary part\n\t⌨🔢 Change the colors with the numeric pad: \n\
	\t- 1 to lower and 2 to raise the blues and reds 🔵🔴\n\
	\t- 4 to lower and 5 to raise the greens and pinks 🟢🧶\n\
	\t- 7 to lower and 8 to raise the purples and yellows 🟣🟡\n\
	\t- 0 to go back to the original set 🌈\n\
	🎨🖼- Improve the details on your fractal with 9 \n\
	(mind that it will increase the calculation time)\n\
	⌛⌛ Lower the details with 6\n\t--------------- 👾👾 \
	ENJOY 👾👾 ---------------\n\n");
}

int	color_set(int keysym, t_fractals *fractal)
{
	if (keysym == PAD_1)
		fractal->color_rb--;
	else if (keysym == PAD_2)
		fractal->color_rb++;
	else if (keysym == PAD_4)
		fractal->color_gpi--;
	else if (keysym == PAD_5)
		fractal->color_gpi++;
	else if (keysym == PAD_7)
		fractal->color_ypu--;
	else if (keysym == PAD_8)
		fractal->color_ypu++;
	else if (keysym == PAD_0)
	{
		fractal->color_rb = 12;
		fractal->color_gpi = 11;
		fractal->color_ypu = 15;
	}
	return (0);
}

void	mouse_down(t_fractals *fractal, int x, int y)
{
	fractal->min_x = fractal->center_x - \
	fractal->med_x * (1 + 0.2) * ((double)x / WIDTH);
	fractal->max_x = fractal->center_x + \
	fractal->med_x * (1 + 0.2) * (1 - (double)x / WIDTH);
	fractal->min_y = fractal->center_y - \
	fractal->med_y * (1 + 0.2) * ((double)y / HEIGHT);
	fractal->max_y = fractal->center_y + \
	fractal->med_y * (1 + 0.2) * (1 - (double)y / HEIGHT);
}

void	mouse_up(t_fractals *fractal, int x, int y)
{
	fractal->min_x = fractal->center_x - \
	fractal->med_x / (1 + 0.2) * ((double)x / WIDTH);
	fractal->max_x = fractal->center_x + \
	fractal->med_x / (1 + 0.2) * (1 - ((double)x / WIDTH));
	fractal->min_y = fractal->center_y - \
	fractal->med_y / (1 + 0.2) * ((double)y / HEIGHT);
	fractal->max_y = fractal->center_y + \
	fractal->med_y / (1 + 0.2) * (1 - ((double)y / HEIGHT));
}

int	ft_error_julia(int argc, char **argv)
{
	double	value1;
	double	value2;

	if (argc != 2 && argc != 4)
		return (0);
	if (argc == 4 && (ft_strlen(argv[2]) > 11 || ft_strlen(argv[3]) > 11))
		return (0);
	if (!(ft_isalldigits(argv[2]) && ft_isalldigits(argv[3])))
		return (0);
	else
	{
		value1 = ft_atod(argv[2]);
		value2 = ft_atod(argv[3]);
		if (!(value1 >= INT_MIN && value1 <= INT_MAX) || \
		!(value2 >= INT_MIN && value2 <= INT_MAX))
			return (0);
	}
	return (1);
}
