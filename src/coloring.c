/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coloring.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 17:16:50 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/09 17:28:28 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	ft_interpolate(uint32_t color1, uint32_t color2, float fraction)
{
	t_color	c1;
	t_color	c2;

	c1.r = (color1 >> 24) & 0xff;
	c2.r = (color2 >> 24) & 0xff;
	c1.g = (color1 >> 16) & 0xff;
	c2.g = (color2 >> 16) & 0xff;
	c1.b = (color1 >> 8) & 0xff;
	c2.b = (color2 >> 8) & 0xff;
	return ((uint32_t)(((c2.r - c1.r) * fraction) + c1.r) << 24 | \
			(uint32_t)(((c2.g - c1.g) * fraction) + c1.g) << 16 | \
			(uint32_t)(((c2.b - c1.b) * fraction) + c1.b) << 8 | 255);
}

static uint32_t	ft_setcolor(int32_t iter)
{
	t_color	color;

	color.a = 255;
	color.b = (uint8_t)(sin(0.3 * iter + 0) * 127 + 128);
	color.g = (uint8_t)(sin(0.3 * iter + 2) * 127 + 128);
	color.r = (uint8_t)(sin(0.3 * iter + 4) * 127 + 128);
	return (color.rgba);
}

uint32_t	ft_normaliseiter(t_xy *z, float iter)
{
	double			log_zn;
	double			nu;
	uint32_t		color1;
	uint32_t		color2;
	const double	log2 = log(2);

	log_zn = log((z->x * z->x) + (z->y * z->y)) / 2;
	nu = log(log_zn / log2) / log2;
	color1 = ft_setcolor(iter);
	color2 = ft_setcolor(iter + 1);
	return (ft_interpolate(color1, color2, fmod((iter - nu), 1)));
}
