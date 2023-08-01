/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 14:14:42 by cschabra      #+#    #+#                 */
/*   Updated: 2023/08/01 15:29:29 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"
# define HEIGHT_WINDOW 500
# define WIDTH_WINDOW 500
# define MAX_ITER 250

/* ************************************************************************** */
/**
 * @brief mouse position handling for julia set and zoom.
 * 
 * @param xpos mouse position on x-axis.
 * @param ypos mouse position on y-axis.
 * @param cx calculated constant for real part.
 * @param cy calculated constant for imaginary part.
 */
typedef struct mouse
{
	double	xpos;
	double	ypos;
	double	cx;
	double	cy;
}	t_mouse;

/**
 * @brief data received from mlx functions to zoom or pan.
 * 
 * @param ydelta value from scrolling up or down.
 * @param key value from pressing arrow keys.
 */
typedef struct s_movement
{
	double	ydelta;
	int32_t	key;
}	t_move;

typedef void	(*t_fractal_func)(mlx_t *mlx, mlx_image_t *img, \
				t_move *movement, t_mouse *mousepos);

/**
 * @brief struct for rendering the right fratal set.
 * 
 * @param name char	*name of possible fractal sets.
 * @param render the chosen fractal set's function.
 */
typedef struct s_fractal
{
	char			*name;
	t_fractal_func	render;
}	t_fractal;

/**
 * @brief struct to initialize and store necessary things.
 * 
 * @param fractal used to store render.
 * @param mlx store * to mlx handle.
 * @param img store * to mlx image.
 * @param mouse store mouse position.
 * @param scroll store scroll data.
 * @param arrows store arrowkey data.
 */
typedef struct s_init
{
	t_fractal	fractal;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_mouse		mouse;
	t_move		scroll;
	t_move		arrows;
}	t_init;

/* ************************************************************************** */

/**
 * @brief x and y coordinates where x = real numbers(horizontal) and
 * y = simulated imaginary numbers(vertical).
 * 
 * @param xmin start coordinate within the fractal sets.
 * @param xmax end coordinate within the fractal sets.
 * @param ymin start coordinate within the fractal sets.
 * @param ymax end coordinate within the fractal sets.
 * @param dx x delta added to x0.
 * @param dy y delta added to y0.
 * @param y0 scaled startpoint for y axis.
 * @param x0 scaled startpoint for x axis.
 * @param x x point in the plot area.
 * @param y y point in the plot area.
 * @param tempx temporary variable for calculations with x.
 * @param w used to iterate through window width.
 * @param h used to iterate through window heigth.
 */
typedef struct s_xy
{
	long double		xmin;
	long double		xmax;
	long double		ymin;
	long double		ymax;
	long double		dx;
	long double		dy;
	long double		y0;
	long double		x0;
	long double		x;
	long double		y;
	long double		tempx;
	uint32_t		w;
	uint32_t		h;
}	t_xy;

/* ************************************************************************** */

/**
 * @brief used to set the rgba values.
 * 
 * @param rgba all channels combined to an unsigned int.
 * @param a alpha channel.
 * @param b blue channel.
 * @param g green channel.
 * @param r red channel.
 */
typedef union s_color
{
	uint32_t	rgba;
	struct
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	};
}	t_color;

/* ************************************************************************** */

uint32_t	ft_normaliseiter(t_xy *z, float iter);

void		ft_julia(mlx_t *mlx, mlx_image_t *img, \
			t_move *movement, t_mouse *mousepos);

void		ft_mandelbrot(mlx_t *mlx, mlx_image_t *img, \
			t_move *movement, t_mouse *mousepos);

void		ft_mousepos(double xpos, double ypos, void *param);
void		ft_scroll(double xdelta, double ydelta, void *param);
void		ft_resize(int32_t width, int32_t height, void *param);

void		ft_viewport(mlx_t *mlx, t_xy *z);
void		ft_zoom(double *zoom, long double *zoomfactor, \
			t_xy *z, t_mouse *mousepos);
void		ft_panning(uint32_t key, t_xy *z, long double zoomfactor);

#endif
