/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:13:42 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/03 10:19:29 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			burningship_choose_color(t_fractal *f, t_color *color)
{
	if (f->a >= DEPTH_BURNINGSHIP)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = sinf((float)f->a / DEPTH_BURNINGSHIP) * 67;
		color->g = sinf((float)f->a / DEPTH_BURNINGSHIP) * 255;
		color->b = sinf((float)f->a / DEPTH_BURNINGSHIP) * 239;
	}
}

void			burningship_depth_loop(t_env *e, t_fractal *f)
{
	f->rz = 0;
	f->iz = 0;
	f->a = 0;
	while (f->a < DEPTH_BURNINGSHIP)
	{
		f->r = f->rz;
		f->i = f->iz;
		f->rz = f->r * f->r - f->i * f->i + f->rc;
		f->iz = 2 * fabs(f->r * f->i) + f->ic;
		if ((f->rz * f->rz + f->iz * f->iz) >= 4)
			break ;
		f->a++;
	}
}

void			burningship_horizontal_loop(t_env *e, t_fractal *f)
{
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->rc = f->min_x + (f->max_x - f->min_x) / WIDTH * (f->x / e->zoom);
		f->ic = f->min_y + (f->max_y - f->min_y) / HEIGHT * (f->y / e->zoom);
		burningship_depth_loop(e, f);
		burningship_choose_color(f, &(e->color));
		ft_put_pixel_to_image(&(e->i), f->x, f->y, e->color);
		f->y++;
	}
}

void			burningship_vertical_loop(t_env *e, t_fractal *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		burningship_horizontal_loop(e, f);
		f->x++;
	}
}

t_fractal		init_burningship(t_env *e)
{
	e->f.min_x = -2.4;
	e->f.max_x = 2.4;
	e->f.min_y = -1.5;
	e->f.max_y = 1.5;
	return (e->f);
}
