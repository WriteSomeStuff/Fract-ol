/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:55:51 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/02 15:25:22 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_algorithm(t_xy *z, mlx_image_t *img, t_mouse *mousepos)
{
	t_color	within;
	int32_t	iter;

	z->x = z->x0;
	z->y = z->y0;
	mousepos->cx = sin(mousepos->xpos / 100);
	mousepos->cy = sin(mousepos->ypos / 100);
	within = (t_color){.rgba = 0x000000FF};
	iter = 0;
	while ((z->x * z->x) + (z->y * z->y) <= (1 << 16) && iter < MAX_ITER)
	{
		z->tempx = z->x * z->x - z->y * z->y + mousepos->cx;
		z->y = 2.0 * z->x * z->y + mousepos->cy;
		z->x = z->tempx;
		iter++;
	}
	if (z->w >= 0 && z->w < img->width
		&& z->h >= 0 && z->h < img->height)
	{
		if (iter < MAX_ITER)
			mlx_put_pixel(img, z->w, z->h, ft_normaliseiter(z, iter));
		else
			mlx_put_pixel(img, z->w, z->h, within.rgba);
	}
}

void	ft_julia(mlx_t *mlx, mlx_image_t *img, \
		t_move *movement, t_mouse *mousepos)
{
	static t_xy			z;
	static long double	zoomfactor = 1;

	if (zoomfactor == 1)
		ft_viewport(mlx, &z);
	if (movement->ydelta != 0)
		ft_zoom(&movement->ydelta, &zoomfactor, &z, mousepos);
	if (movement->key != 0)
		ft_panning(movement->key, &z, zoomfactor);
	z.y0 = z.ymin;
	while (z.h < (uint32_t)mlx->height)
	{
		z.x0 = z.xmin;
		while (z.w < (uint32_t)mlx->width)
		{
			ft_algorithm(&z, img, mousepos);
			z.x0 += z.dx * zoomfactor;
			z.w++;
		}
		z.y0 += z.dy * zoomfactor;
		z.h++;
		z.w = 0;
	}
	z.h = 0;
}
