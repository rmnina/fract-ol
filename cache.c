/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:18 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/26 20:48:26 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	**create_cache(int width, int height)
{
	int **cache;
	int x;
	int y;

	x = 0;
	cache = malloc(width * sizeof(int*));
	if (!cache)
	{
		free(cache);
		return (NULL);
	}
	while (x < width)
	{
		y = 0;
		cache[x] = malloc(height * sizeof(int));
		if (!cache[x])
		{
			ft_free_cache(cache, width);
			return (NULL);
		}
		while (y < height)
		{
			cache[x][y] = -1;
			y++;
		}
		x++;
	}
	return (cache);
}

int	ft_isincache(t_fractals *fractal, int x, int y)
{
	return (fractal->cache[x][y] != -1);
}

int	ft_getorcalculate(t_fractals *fractal, int x, int y)
{
	if (ft_isincache(fractal, x, y))
		return (fractal->iterations = fractal->cache[x][y]);
	else
	{
		fractal->x = fractal->min_x + (fractal->max_x - fractal->min_x) * x / (WIDTH);
		fractal->y = fractal->min_y + (fractal->max_y - fractal->min_y) * y / (HEIGHT);
		fractal->iterations = fractal->fract(fractal);
		fractal->cache[x][y] = fractal->iterations;
	}
	return (fractal->iterations);
}

void	update_cache(t_fractals *fractal)
{
	int	x;
	int	y;
	
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->cache[x][y] = -1;
			y++;
		}
		x++;
	}
}

void	update_cache_after_move(t_fractals *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (!(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
				fractal->cache[x][y] = -1;
			else
				fractal->cache[x][y] = fractal->cache[x][y];
			y++;
		}
		x++;
	}
}

void	ft_free_cache(int **cache, int width)
{
	int x;

	x = 0;
	while (x < width)
	{
		free(cache[x]);
		x++;
	}
	free(cache);
}