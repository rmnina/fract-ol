/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:49:49 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/12 19:24:01 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int ft_rainbow(int iterations)
{
    int color;

    color = 0;
    if (iterations < 2)
        color = 0x00c27ba0 + (iterations * 0x00001000); //rose
    else if (iterations < 4)
        color = 0x008e7cc3 + (iterations * 0x00001000); //violet
    else if (iterations < 6)
        color = 0x006fa8dc + (iterations * 0x00001000); //bleu
    else if (iterations < 8)
        color = 0x0076a5af + (iterations * 0x00001000); //vert-bleu
    else if (iterations < 10)
        color = 0x0093c47d + (iterations * 0x00001000); //vert
    else if (iterations < 20)
        color = 0x00ffd966 + (iterations * 0x00001000); //jaune
    else if (iterations < 50)
        color = 0x00f6b26b + (iterations * 0x00001000); //orange
    else
        color = 0x00e06666 + (iterations * 0x00001000); //rouge
    return (color);
}