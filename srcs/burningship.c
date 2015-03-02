/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 13:11:51 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 15:20:00 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			burningship_choose_color(t_fractal *b, t_color *color)
{
	if (b->a >= DEPTH_BURNINGSHIP)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = sinf((float)b->a / DEPTH_BURNINGSHIP) * 67;
		color->g = sinf((float)b->a / DEPTH_BURNINGSHIP) * 255;
		color->b = sinf((float)b->a / DEPTH_BURNINGSHIP) * 239;
	}
}

void			burningship_depth_loop(t_env *e, t_fractal *b)
{
	b->rz = 0;
	b->iz = 0;
	b->a = 0;
	while (b->a < DEPTH_BURNINGSHIP)
	{
		b->r = b->rz;
		b->i = b->iz;
		b->rz = b->r * b->r - b->i * b->i + b->rc;
		b->iz = 2 * fabs(b->r * b->i) + b->ic;
		if ((b->rz * b->rz + b->iz * b->iz) >= 4)
			break ;
		b->a++;
	}
}

void			burningship_horizontal_loop(t_env *e, t_fractal *b)
{
	b->y = 0;
	while (b->y < HEIGHT)
	{
		b->rc = b->minX + (b->maxX - b->minX) / WIDTH * (b->x / e->zoom);
		b->ic = b->minY + (b->maxY - b->minY) / HEIGHT * (b->y / e->zoom);
		burningship_depth_loop(e, b);
		burningship_choose_color(b, &(e->color));
		ft_put_pixel_to_image(&(e->i), b->x, b->y, e->color);
		b->y++;
	}
}

void			burningship_vertical_loop(t_env *e, t_fractal *b)
{
	b->x = 0;
	while (b->x < WIDTH)
	{
		burningship_horizontal_loop(e, b);
		b->x++;
	}
}

t_fractal	init_burningship(t_env *e)
{
	e->b.minX = -2.4;
	e->b.maxX = 2.4;
	e->b.minY = -1.5;
	e->b.maxY = 1.5;

	return (e->b);
}
