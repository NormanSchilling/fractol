/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:55:39 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 15:46:28 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			mandelbrot_choose_color(t_fractal *m, t_color *color)
{
	if (m->a >= DEPTH_MANDELBROT)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = sinf((float)m->a / DEPTH_BURNINGSHIP) * 214;
		color->g = sinf((float)m->a / DEPTH_BURNINGSHIP) * 230;
		color->b = sinf((float)m->a / DEPTH_BURNINGSHIP) * 255;
	}
}

void			mandelbrot_depth_loop(t_env *e, t_fractal *m)
{
	m->rz = 0;
	m->iz = 0;
	m->a = 0;
	while (m->a < DEPTH_MANDELBROT)
	{
		m->r = m->rz;
		m->i = m->iz;
		m->rz = m->r * m->r - m->i * m->i + m->rc;
		m->iz = 2 * m->r * m->i + m->ic;
		if ((m->rz * m->rz + m->iz * m->iz) >= 4)
			break ;
		m->a++;
	}
}

void			mandelbrot_horizontal_loop(t_env *e, t_fractal *m)
{
	t_color		color;

	m->y = 0;
	while (m->y < HEIGHT)
	{
		m->rc = m->min_x + (m->max_x - m->min_x) / WIDTH * (m->x / e->zoom);
		m->ic = m->min_y + (m->max_y - m->min_y) / HEIGHT * (m->y / e->zoom);
		mandelbrot_depth_loop(e, m);
		mandelbrot_choose_color(m, &(e->color));
		ft_put_pixel_to_image(&(e->i), m->x, m->y, e->color);
		m->y++;
	}
}

void			mandelbrot_vertical_loop(t_env *e, t_fractal *m)
{
	m->x = 0;
	while (m->x < WIDTH)
	{
		mandelbrot_horizontal_loop(e, m);
		m->x++;
	}
}

t_fractal		init_mandelbrot(t_env *e)
{
	e->m.min_x = -2.4;
	e->m.max_x = 2.4;
	e->m.min_y = -1.5;
	e->m.max_y = 1.5;
	return (e->m);
}
