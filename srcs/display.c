/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:01:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/25 14:20:26 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_put_pixel_to_image(t_image *i, int x, int y, t_color color)
{
	int		index;

	index = (y * i->size_line) + ((x * i->bits_per_pixel) / 8);
	i->data[index] = color.r;
	i->data[index + 1] = color.g;
	i->data[index + 2] = color.b;
}

void		ft_display(t_env *e)
{
	display_mandelbrot(e);
	mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
}

int			key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int			expose_hook(t_env *e)
{
	ft_display(e);
	return (0);
}

void		ft_init(char *fractol)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 800, 700, "Fractol");
	e.i.image = mlx_new_image ( e.mlx, ITERATION_MANDELBROT_X, ITERATION_MANDELBROT_Y );
	e.i.data = mlx_get_data_addr ( e.i.image, &(e.i.bits_per_pixel), &(e.i.size_line), &(e.i.endian) );
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
