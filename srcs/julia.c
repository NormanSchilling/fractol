/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:51:13 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/25 16:20:11 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_depth_loop(t_env *e, t_julia *j)
{
	j->a = 0;
	while (j->a < DEPTH_JULIA)
	{
		j->oldre = j->newre;
		j->oldim = j->newim;
		j->newre = j->oldre * j->oldre - j->oldim * j->oldim + j->rc;
		j->newim = 2 * j->oldre * j->oldim + j->ic;
		if ((j->newre * j->newre + j->newim * j->newim) >= 4)
			break ;
		j->a++;
	}
}

void		julia_horizontal_loop(t_env *e, t_julia *j)
{
	t_color		color;

	j->y = 0;
	while (j->y < HEIGHT)
	{
		j->newre = 1.5 * (j->x - WIDTH / 2) / (0.5 * j->zoom * WIDTH) + j->moveX;
		j->newim = (j->y - HEIGHT / 2) / (0.5 * j->zoom * HEIGHT) + j->moveY;
		julia_depth_loop(e, j);
		if (j->a >= DEPTH_JULIA)
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
		ft_put_pixel_to_image(&(e->i), j->x, j->y, color);
		j->y++;
	}
}

void		julia_vertical_loop(t_env *e, t_julia *j)
{
	j->x = 0;
	while (j->x < WIDTH)
	{
		julia_horizontal_loop(e, j);
		j->x++;
	}
}

void		display_julia(t_env *e)
{
	t_julia		j;

	j.rc = -0.7;
	j.ic = 0.27015;
	j.moveY = 0;
	j.moveX = 0;
	j.zoom = 1;
	julia_vertical_loop(e, &j);
}

//     color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
