/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:02:15 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/27 02:52:27 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (str[0] == '-')
		sign *= -1;
	return (sign);
}

double	ft_atod(const char *str)
{
	int		i;
	double	res;
	double	div;

	i = 0;
	res = 0;
	div = 10;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (res * ft_sign(str));
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0') / div;
		div *= 10;
		i++;
	}
	return (res * ft_sign(str));
}