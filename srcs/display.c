/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 10:39:52 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/03 10:17:05 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom(t_env *e)
{
	e->f.min_x += e->mouse.x / 5 / e->zoom;
	e->f.max_x += e->mouse.x / 5 / e->zoom;
	e->f.min_y += e->mouse.y / 5 / e->zoom;
	e->f.max_y += e->mouse.y / 5 / e->zoom;
	e->zoom *= 1.015;
}

void		ft_dezoom(t_env *e)
{
	e->f.min_x -= e->mouse.x / 5 / e->zoom;
	e->f.max_x -= e->mouse.x / 5 / e->zoom;
	e->f.min_y -= e->mouse.y / 5 / e->zoom;
	e->f.max_y -= e->mouse.y / 5 / e->zoom;
	e->zoom *= 0.985;
}

void		ft_display(t_env *e)
{
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
	{
		mandelbrot_vertical_loop(e, &(e->f));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
	else if (ft_strcmp(e->fractol, "julia") == 0)
	{
		julia_vertical_loop(e, &(e->f));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
	else if (ft_strcmp(e->fractol, "burningship") == 0)
	{
		burningship_vertical_loop(e, &(e->f));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
	else if (ft_strcmp(e->fractol, "brain") == 0)
	{
		brain_vertical_loop(e, &(e->f));
		mlx_put_image_to_window (e->mlx, e->win, e->i.image, 0, 0);
	}
}
