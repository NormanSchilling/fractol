/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:56:07 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 13:54:45 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		menu(void)
{
	ft_putendl("----- MENU FRACTOL -----");
	ft_putendl("  --- PARAMS ---");
	ft_putendl("  1. mandelbrot");
	ft_putendl("  2. julia");
	ft_putendl("  3. burningship");
}

static int		check_params(char *params)
{
	if (ft_strcmp(params, "mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(params, "julia") == 0)
		return (0);
	else if (ft_strcmp(params, "burningship") == 0)
		return (0);
	return (1);
}

int				main(int argc, char** argv)
{
	srand(time(NULL));

	if (argc == 2)
	{
		if (check_params(argv[1]) == 0)
			ft_init(argv[1]);
		else
		{
			menu();
			return (-1);
		}
	}
	else
	{
		menu();
		return (-1);
	}
	return (0);
}