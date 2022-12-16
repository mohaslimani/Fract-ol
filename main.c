/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 23:29:10 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 22:27:47 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		puthelp(char **argv)
{
	ft_putstr_fd("\ninvalid Type : ", 2);
	ft_putstr_fd(argv[1], 2);
	ft_putstr_fd("\"\n\n", 2);
	ft_putstr_fd("available fractals : \n", 2);
	ft_putstr_fd("\t1           - julia\n", 2);
	ft_putstr_fd("\t2           - mandelbrot\n", 2);
	ft_putstr_fd("\t(3,4,5)     - multibrot_(2,3,4)\n", 2);
	ft_putstr_fd("\t(6,7)       - negative_mandelbrot_(1,2)\n", 2);
	ft_putstr_fd("\t(8,9)       - sierpinski_carpet, sierpinski_triangle\n", 2);
	ft_putstr_fd("\t(10, 11, 12)- tricorn, quadcorne, quint_corne\n", 2);
	ft_putstr_fd("\t13          - burningship\n", 2);
	ft_putstr_fd("\t14          - rorscharch\n", 2);
	ft_putstr_fd("\t15          - sphere\n", 2);
	return (0);
}

void	fract_init(t_fractol *data)
{
	data->name = init_name(data);
	data->img = NULL;
	data->mlx = NULL;
	data->img_ptr = NULL;
	data->win = NULL;
	data->y_max = 2.0;
	data->x_max = 2.0;
	data->x_min = -2.0;
	data->y_min = -2.0;
	data->iter = 100;
	data->color = 2;
	data->zoom = 1;
	data->speed = 0.8;
	data->jul_re = 0.0;
	data->jul_im = 0.0;
	data->pause = 0;
	data->iter_sponge = 5;
	data->moove_x = 0;
	data->moove_y = 0;
	data->iter_s = 300;
	data->zoom_s = 1;
	data->var = 1;
}

int		choose_fractal(t_fractol *data, char **argv)
{
	data->type = 0;
	(ft_strcmp("julia", argv[1]) == 0) ? data->type = 1 : 0;
	(ft_strcmp("mandelbrot", argv[1]) == 0) ? data->type = 2 : 0;
	(ft_strcmp("multibrot_2", argv[1]) == 0) ? data->type = 3 : 0;
	(ft_strcmp("multibrot_3", argv[1]) == 0) ? data->type = 4 : 0;
	(ft_strcmp("multibrot_4", argv[1]) == 0) ? data->type = 5 : 0;
	(ft_strcmp("negative_mandelbrot_1", argv[1]) == 0) ? data->type = 6 : 0;
	(ft_strcmp("negative_mandelbrot_2", argv[1]) == 0) ? data->type = 7 : 0;
	(ft_strcmp("sierpinski_carpet", argv[1]) == 0) ? data->type = 8 : 0;
	(ft_strcmp("sierpinski_triangle", argv[1]) == 0) ? data->type = 9 : 0;
	(ft_strcmp("tricorn", argv[1]) == 0) ? data->type = 10 : 0;
	(ft_strcmp("quadcorne", argv[1]) == 0) ? data->type = 11 : 0;
	(ft_strcmp("quint_corne", argv[1]) == 0) ? data->type = 12 : 0;
	(ft_strcmp("burningship", argv[1]) == 0) ? data->type = 13 : 0;
	(ft_strcmp("rorscharch", argv[1]) == 0) ? data->type = 14 : 0;
	(ft_strcmp("sphere", argv[1]) == 0) ? data->type = 15 : 0;
	if (data->type == 0)
		return (puthelp(argv));
	fract_init(data);
	return (1);
}

int		main(int ac, char **av)
{
	t_fractol	data;

	if (ac == 2)
	{
		if ((choose_fractal(&data, av)) == 0)
			return (1);
		ft_fractol(&data);
	}
	else
		ft_putendl_fd("Usage: /fractol [fractal_name]", 2);
	return (0);
}
