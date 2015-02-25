/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:55:39 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/25 16:42:32 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot_choose_color(t_mandelbrot *m, t_color *color)
{
	if (m->a >= DEPTH_MANDELBROT)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = rand() % 255;
		color->g = rand() % 255;
		color->b = rand() % 255;
	}
}

void		mandelbrot_depth_loop(t_env *e, t_mandelbrot *m)
{
	float	rz;
	float	iz;
	float	r;
	float	i;

	rz = 0;
	iz = 0;
	m->a = 0;
	while (m->a < DEPTH_MANDELBROT)
	{
		r = rz;
		i = iz;
		rz = r * r - i * i + m->rc;
		iz = 2 * r * i + m->ic;
		if ((rz * rz + iz * iz) >= 4)
			break ;
		m->a++;
	}
}

void		mandelbrot_horizontal_loop(t_env *e, t_mandelbrot *m)
{
	t_color		color;

	m->y = 0;
	while (m->y < HEIGHT)
	{
		m->rc = m->minX + (m->maxX - m->minX) / WIDTH * m->x;
		m->ic = m->minY + (m->maxY - m->minY) / HEIGHT * m->y;
		mandelbrot_depth_loop(e, m);
		mandelbrot_choose_color(m, &color);
		ft_put_pixel_to_image(&(e->i), m->x, m->y, color);
		m->y++;
	}
}

void		mandelbrot_vertical_loop(t_env *e, t_mandelbrot *m)
{
	m->x = 0;
	while (m->x < WIDTH)
	{
		mandelbrot_horizontal_loop(e, m);
		m->x++;
	}
}

void		display_mandelbrot(t_env *e)
{
	t_mandelbrot	m;

	m.minX = -2.4;
	m.maxX = 2.4;
	m.minY = -1.5;
	m.maxY = 1.5;

	mandelbrot_vertical_loop(e, &m);
}
