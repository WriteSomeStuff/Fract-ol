/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 11:14:35 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 12:52:03 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mousepos(double xpos, double ypos, void *param)
{
	t_init	*instance;

	instance = param;
	instance->mouse.ypos = 0;
	instance->mouse.xpos = 0;
	if (xpos >= 0 && xpos < instance->mlx->width
		&& ypos >= 0 && ypos < instance->mlx->height)
	{
		instance->mouse.ypos = ypos - (instance->mlx->height / 2);
		instance->mouse.xpos = xpos - (instance->mlx->width / 2);
		instance->fractal.render(instance->mlx, \
		instance->img, &instance->scroll, &instance->mouse);
	}
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_init	*instance;

	instance = param;
	instance->scroll.ydelta = ydelta;
	(void)xdelta;
	if (ydelta != 0)
		instance->fractal.render(instance->mlx, \
		instance->img, &instance->scroll, &instance->mouse);
}

void	ft_resize(int32_t width, int32_t height, void *param)
{
	t_init	*instance;
	bool	check;

	instance = param;
	check = mlx_resize_image(instance->img, width, height);
	if (check == false)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_close_window(instance->mlx);
	}
	else
	{
		instance->mlx->width = width;
		instance->mlx->height = height;
		instance->fractal.render(instance->mlx, \
		instance->img, &instance->scroll, &instance->mouse);
	}
}
