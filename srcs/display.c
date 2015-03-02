/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 10:39:52 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 15:38:42 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom(t_env *e)
{
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
	{
		e->m.min_x += e->mouse.x / 5 / e->zoom;
		e->m.max_x += e->mouse.x / 5 / e->zoom;
		e->m.min_y += e->mouse.y / 5 / e->zoom;
		e->m.max_y += e->mouse.y / 5 / e->zoom;
		e->zoom *= 1.015;
	}
	else if (ft_strcmp(e->fractol, "julia") == 0)
	{
		e->j.min_x += e->mouse.x / 5 / e->zoom;
		e->j.max_x += e->mouse.x / 5 / e->zoom;
		e->j.min_y += e->mouse.y / 5 / e->zoom;
		e->j.max_y += e->mouse.y / 5 / e->zoom;
		e->zoom *= 1.015;
	}
	else if (ft_strcmp(e->fractol, "burningship") == 0)
	{
		e->b.min_x += e->mouse.x / 5 / e->zoom;
		e->b.max_x += e->mouse.x / 5 / e->zoom;
		e->b.min_y += e->mouse.y / 5 / e->zoom;
		e->b.max_y += e->mouse.y / 5 / e->zoom;
		e->zoom *= 1.015;
	}
}

void		ft_dezoom(t_env *e)
{
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
	{
		e->m.min_x -= e->mouse.x / 5 / e->zoom;
		e->m.max_x -= e->mouse.x / 5 / e->zoom;
		e->m.min_y -= e->mouse.y / 5 / e->zoom;
		e->m.max_y -= e->mouse.y / 5 / e->zoom;
		e->zoom *= 0.985;
	}
	else if (ft_strcmp(e->fractol, "julia") == 0)
	{
		e->j.min_x += e->mouse.x / 5 / e->zoom;
		e->j.max_x += e->mouse.x / 5 / e->zoom;
		e->j.min_y += e->mouse.y / 5 / e->zoom;
		e->j.max_y += e->mouse.y / 5 / e->zoom;
		e->zoom *= 0.985;
	}
	else if (ft_strcmp(e->fractol, "burningship") == 0)
	{
		e->b.min_x += e->mouse.x / 5 / e->zoom;
		e->b.max_x += e->mouse.x / 5 / e->zoom;
		e->b.min_y += e->mouse.y / 5 / e->zoom;
		e->b.max_y += e->mouse.y / 5 / e->zoom;
		e->zoom *= 0.985;
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
	else if (ft_strcmp(e->fractol, "burningship") == 0)
	{
		burningship_vertical_loop(e, &(e->b));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
}
