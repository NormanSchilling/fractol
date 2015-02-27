/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 10:39:52 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/27 16:18:45 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom(t_env *e)
{
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
	{
		e->m.minX += e->mouse.x/5/e->zoom;
		e->m.maxX += e->mouse.x/5/e->zoom;
		e->m.minY += e->mouse.y/5/e->zoom;
		e->m.maxY += e->mouse.y/5/e->zoom;

		e->zoom *= 1.005;
	}
	else if (ft_strcmp(e->fractol, "julia") == 0)
	{
		e->j.minX += e->mouse.x/5/e->zoom;
		e->j.maxX += e->mouse.x/5/e->zoom;
		e->j.minY += e->mouse.y/5/e->zoom;
		e->j.maxY += e->mouse.y/5/e->zoom;
		e->zoom *= 1.005;
	}
}

void		ft_dezoom(t_env *e)
{
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
	{
		e->m.minX -= e->mouse.x/5/e->zoom;
		e->m.maxX -= e->mouse.x/5/e->zoom;
		e->m.minY -= e->mouse.y/5/e->zoom;
		e->m.maxY -= e->mouse.y/5/e->zoom;
		e->zoom *= 0.995;
	}
	else if (ft_strcmp(e->fractol, "julia") == 0)
	{
		e->j.minX += e->mouse.x/5/e->zoom;
		e->j.maxX += e->mouse.x/5/e->zoom;
		e->j.minY += e->mouse.y/5/e->zoom;
		e->j.maxY += e->mouse.y/5/e->zoom;
		e->zoom *= 0.995;
	}
}

void		ft_display(t_env *e)
{
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
	{
		mandelbrot_vertical_loop(e, &(e->m));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
	else if (ft_strcmp(e->fractol, "julia") == 0)
	{
		julia_vertical_loop(e, &(e->j));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
}