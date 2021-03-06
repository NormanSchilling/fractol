/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:01:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/03 10:17:55 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_put_pixel_to_image(t_image *i, int x, int y, t_color color)
{
	int		index;

	index = (y * i->size_line) + ((x * i->bits_per_pixel) / 8);
	i->data[index] = color.b;
	i->data[index + 1] = color.g;
	i->data[index + 2] = color.r;
}

double		get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + (double)tv.tv_usec / 1000000);
}

int			main_loop(t_env *e)
{
	double		start;
	double		end;

	start = get_time();
	ft_display(e);
	end = get_time();
	usleep((1000000 / 30) - (end - start));
}

void		ft_init(char *fractol)
{
	t_env	e;

	e.zoom = 1.0;
	e.fractol = ft_strdup(fractol);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
	if (ft_strcmp(e.fractol, "mandelbrot") == 0)
		e.f = init_mandelbrot(&e);
	if (ft_strcmp(e.fractol, "julia") == 0)
		e.f = init_julia(&e);
	if (ft_strcmp(e.fractol, "burningship") == 0)
		e.f = init_burningship(&e);
	if (ft_strcmp(e.fractol, "brain") == 0)
		e.f = init_brain(&e);
	e.i.image = mlx_new_image (e.mlx, WIDTH, HEIGHT);
	e.i.data = mlx_get_data_addr (e.i.image, &(e.i.bits_per_pixel),
	&(e.i.size_line), &(e.i.endian));
	mlx_hook(e.win, KeyPress, KeyPressMask, &key_hook, &e);
	mlx_hook(e.win, ButtonPress, ButtonPressMask, &mouse_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, &mouse_hook_position, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook (e.mlx, main_loop, &e);
	mlx_loop(e.mlx);
}
