/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 16:55:51 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/09 13:21:36 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_viewport(mlx_t *mlx, t_xy *z)
{
	(*z) = (t_xy){.xmin = -2.00, .xmax = 2.00, .ymin = -2.00, .ymax = 2.00};
	z->dx = ((z->xmax - z->xmin) / mlx->width);
	z->dy = ((z->ymax - z->ymin) / mlx->height);
	z->w = 0;
	z->h = 0;
}

void	ft_zoom(double *zoom, long double *zoomfactor, \
		t_xy *z, t_mouse *mousepos)
{
	if (*zoom > 0)
	{
		*zoomfactor *= 0.9;
		z->xmin += mousepos->xpos * 0.005 * *zoomfactor;
		z->xmax += mousepos->xpos * 0.005 * *zoomfactor;
		z->ymin += mousepos->ypos * 0.005 * *zoomfactor;
		z->ymax += mousepos->ypos * 0.005 * *zoomfactor;
	}
	else if (*zoom < 0)
	{
		*zoomfactor *= 1.1;
		z->xmin -= mousepos->xpos * 0.005 * *zoomfactor;
		z->xmax -= mousepos->xpos * 0.005 * *zoomfactor;
		z->ymin -= mousepos->ypos * 0.005 * *zoomfactor;
		z->ymax -= mousepos->ypos * 0.005 * *zoomfactor;
	}
	*zoom = 0;
}

void	ft_panning(uint32_t key, t_xy *z, long double zoomfactor)
{
	if (key == MLX_KEY_UP)
	{
		z->ymin -= zoomfactor;
		z->ymax -= zoomfactor;
	}
	if (key == MLX_KEY_DOWN)
	{
		z->ymin += zoomfactor;
		z->ymax += zoomfactor;
	}
	if (key == MLX_KEY_LEFT)
	{
		z->xmin -= zoomfactor;
		z->xmax -= zoomfactor;
	}
	if (key == MLX_KEY_RIGHT)
	{
		z->xmin += zoomfactor;
		z->xmax += zoomfactor;
	}
}
