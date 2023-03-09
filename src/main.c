/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <main@w2wizard.dev>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:33:41 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 16:50:50 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keypress(mlx_key_data_t keydata, void *param)
{
	t_init	*instance;

	instance = param;
	instance->arrows.key = keydata.key;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(instance->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN || \
		keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT) && \
		keydata.action == MLX_PRESS)
		instance->fractal.render(instance->mlx, \
		instance->img, &instance->arrows, &instance->mouse);
}

static t_fractal_func	ft_get_render(int32_t argc, char *input)
{
	int32_t		i;
	t_fractal	option[2];
	int32_t		maxlen;

	if (argc != 2)
		return (NULL);
	i = 0;
	option[0] = (t_fractal){.name = "mandelbrot", .render = ft_mandelbrot};
	option[1] = (t_fractal){.name = "julia", .render = ft_julia};
	while (i < 2)
	{
		maxlen = ft_strlen(option[i].name) + 1;
		if (ft_strncmp(option[i].name, input, maxlen) == 0)
			return (option[i].render);
		i++;
	}
	return (NULL);
}

void	ft_hooks(t_init instance)
{
	mlx_key_hook(instance.mlx, ft_keypress, &instance);
	mlx_cursor_hook(instance.mlx, ft_mousepos, &instance);
	mlx_scroll_hook(instance.mlx, ft_scroll, &instance);
	mlx_resize_hook(instance.mlx, ft_resize, &instance);
}

bool	ft_init(t_init *instance)
{
	if (instance->fractal.render == NULL)
	{
		ft_putendl_fd("try: ./fractol mandelbrot or ./fractol julia", \
		STDERR_FILENO);
		return (true);
	}
	instance->mlx = mlx_init(WIDTH_WINDOW, HEIGHT_WINDOW, "Fractol", true);
	if (!instance->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (true);
	}
	instance->img = mlx_new_image(instance->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	if (!instance->img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_terminate(instance->mlx);
		return (true);
	}
	instance->fractal.render(instance->mlx, instance->img, \
	&instance->scroll, &instance->mouse);
	return (false);
}

int32_t	main(int32_t argc, char **argv)
{
	t_init	instance;

	instance.scroll.ydelta = 0;
	instance.mouse.cx = 0;
	instance.mouse.cy = 0;
	instance.arrows.key = 0;
	instance.fractal.render = ft_get_render(argc, argv[1]);
	if (ft_init(&instance))
		return (EXIT_FAILURE);
	if (mlx_image_to_window(instance.mlx, instance.img, 0, 0) == -1)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_terminate(instance.mlx);
		return (EXIT_FAILURE);
	}
	ft_hooks(instance);
	mlx_loop(instance.mlx);
	mlx_terminate(instance.mlx);
	return (EXIT_SUCCESS);
}
