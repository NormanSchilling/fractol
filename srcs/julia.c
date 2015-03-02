/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:51:13 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 15:16:58 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia_choose_color(t_fractal *j, t_color *color)
{
	if (j->a >= DEPTH_JULIA)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		if (j->a == 0)
		{
			color->r = sinf((float)j->a / DEPTH_BURNINGSHIP) * 214;
			color->g = sinf((float)j->a / DEPTH_BURNINGSHIP) * 230;
			color->b = sinf((float)j->a / DEPTH_BURNINGSHIP) * 255;
		}
		else if (j->a == 1)
		{
			color->r = sinf((float)j->a / DEPTH_BURNINGSHIP) * 67;
			color->g = sinf((float)j->a / DEPTH_BURNINGSHIP) * 255;
			color->b = sinf((float)j->a / DEPTH_BURNINGSHIP) * 239;
		}
	}
}

void			julia_depth_loop(t_env *e, t_fractal *j)
{
	j->a = 0;
	while (j->a < DEPTH_JULIA)
	{
		j->r = j->rz;
		j->i = j->iz;
		j->rz = j->r * j->r - j->i * j->i + j->rc;
		j->iz = 2 * j->r * j->i + j->ic;
		if ((j->rz * j->rz + j->iz * j->iz) >= 4)
			break ;
		j->a++;
	}
}

void			julia_horizontal_loop(t_env *e, t_fractal *j)
{
	t_color		color;

	j->y = 0;
	while (j->y < HEIGHT)
	{
		j->rz = j->minX + (j->maxX - j->minX) / WIDTH * (j->x / e->zoom);
		j->iz = j->minY + (j->maxY - j->minY) / HEIGHT * (j->y / e->zoom);
		julia_depth_loop(e, j);
		julia_choose_color(j, &(e->color));
		ft_put_pixel_to_image(&(e->i), j->x, j->y, e->color);
		j->y++;
	}
}

void			julia_vertical_loop(t_env *e, t_fractal *j)
{
	j->x = 0;
	while (j->x < WIDTH)
	{
		julia_horizontal_loop(e, j);
		j->x++;
	}
}

t_fractal	init_julia(t_env *e)
{
	e->j.minX = -2.4;
	e->j.maxX = 2.4;
	e->j.minY = -1.5;
	e->j.maxY = 1.5;
	e->j.rc = 0.5;
	e->j.ic = 0.5;
	return (e->j);
}
