/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:55:39 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/25 14:30:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_depth_loop(t_env *e, t_mandelbrot *m)
{
	float	rz;
	float	iz;
	float	r;
	float	i;

	rz = 0;
	iz = 0;
	m->a = 0;
	while (m->a < ITERATION_MANDELBROT_Z)
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

void		ft_horizontal_loop(t_env *e, t_mandelbrot *m)
{
	t_color		color;

	m->y = 0;
	while (m->y < ITERATION_MANDELBROT_Y)
	{
		m->rc = m->minX + (m->maxX - m->minX) / ITERATION_MANDELBROT_X * m->x;
		m->ic = m->minY + (m->maxY - m->minY) / ITERATION_MANDELBROT_Y * m->y;
		ft_depth_loop(e, m);
		if (m->a >= ITERATION_MANDELBROT_Z)
		{
			color.r = 0;
			color.g = 0;
			color.b = 0;
		}
		else
		{
			color.r = 0;
			color.g = 50;
			color.b = 215;
		}
		ft_put_pixel_to_image(&(e->i), m->x, m->y, color);
		m->y++;
	}
}


void		ft_vertical_loop(t_env *e, t_mandelbrot *m)
{
	m->x = 0;
	while (m->x < ITERATION_MANDELBROT_X)
	{
		ft_horizontal_loop(e, m);
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

	ft_vertical_loop(e, &m);
}
