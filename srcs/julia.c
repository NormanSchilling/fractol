/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:51:13 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/03 10:11:46 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia_choose_color(t_fractal *f, t_color *color)
{
	if (f->a >= DEPTH_JULIA)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = sinf((float)f->a / DEPTH_JULIA) * 214;
		color->g = sinf((float)f->a / DEPTH_JULIA) * 230;
		color->b = sinf((float)f->a / DEPTH_JULIA) * 255;
	}
}

void			julia_depth_loop(t_env *e, t_fractal *f)
{
	f->a = 0;
	while (f->a < DEPTH_JULIA)
	{
		f->r = f->rz;
		f->i = f->iz;
		f->rz = f->r * f->r - f->i * f->i + f->rc;
		f->iz = 2 * f->r * f->i + f->ic;
		if ((f->rz * f->rz + f->iz * f->iz) >= 4)
			break ;
		f->a++;
	}
}

void			julia_horizontal_loop(t_env *e, t_fractal *f)
{
	t_color		color;

	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->rz = f->min_x + (f->max_x - f->min_x) / WIDTH * (f->x / e->zoom);
		f->iz = f->min_y + (f->max_y - f->min_y) / HEIGHT * (f->y / e->zoom);
		julia_depth_loop(e, f);
		julia_choose_color(f, &(e->color));
		ft_put_pixel_to_image(&(e->i), f->x, f->y, e->color);
		f->y++;
	}
}

void			julia_vertical_loop(t_env *e, t_fractal *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		julia_horizontal_loop(e, f);
		f->x++;
	}
}

t_fractal		init_julia(t_env *e)
{
	e->f.min_x = -2.4;
	e->f.max_x = 2.4;
	e->f.min_y = -1.5;
	e->f.max_y = 1.5;
	e->f.rc = 0.5;
	e->f.ic = 0.5;
	return (e->f);
}
