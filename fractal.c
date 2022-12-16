/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 02:24:56 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 19:14:32 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_fractol *data, long double col, long double row)
{
	t_complex		z;
	t_complex		c;
	long double		tmp;
	int				iter;

	c.re = data->x_min + ((data->x_max - data->x_min) / IMG_WIDTH) * col;
	c.im = data->y_min + ((data->y_max - data->y_min) / IMG_WIDTH) * row;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < data->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_color(data, iter));
}

int		multibrot_2(t_fractol *data, long double col, long double row)
{
	t_complex		z;
	t_complex		c;
	int				iter;
	long double		tmp;

	c.re = data->x_min + ((data->x_max - data->x_min) / IMG_WIDTH) * col;
	c.im = data->y_min + ((data->y_max - data->y_min) / IMG_WIDTH) * row;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < data->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = 3 * tmp * tmp * z.im - z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_color(data, iter));
}

int		multibrot_3(t_fractol *data, long double col, long double row)
{
	t_complex		z;
	t_complex		c;
	int				iter;
	long double		tmp;

	c.re = data->x_min + ((data->x_max - data->x_min) / IMG_WIDTH) * col;
	c.im = data->y_min + ((data->y_max - data->y_min) / IMG_WIDTH) * row;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < data->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re * z.re * z.re -
		6 * z.re * z.re * z.im * z.im + z.im * z.im * z.im * z.im + c.re;
		z.im = 4 * tmp * z.im * (tmp * tmp - z.im * z.im) + c.im;
		iter++;
	}
	return (ft_color(data, iter));
}

int		multibrot_4(t_fractol *data, long double col, long double row)
{
	int				iter;
	t_complex		z;
	t_complex		c;
	long double		tmp;

	c.re = data->x_min + ((data->x_max - data->x_min) / IMG_WIDTH) * col;
	c.im = data->y_min + ((data->y_max - data->y_min) / IMG_WIDTH) * row;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < data->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re * z.re * z.re * z.re -
		10 * z.re * z.re * z.re * z.im * z.im +
		5 * z.re * z.im * z.im * z.im * z.im + c.re;
		z.im = 5 * tmp * tmp * tmp * tmp * z.im -
		10 * tmp * tmp * z.im * z.im * z.im +
		z.im * z.im * z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_color(data, iter));
}

int		negative_mandelbrot_1(t_fractol *p, long double col, long double row)
{
	int				iter;
	t_complex		z;
	t_complex		c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_WIDTH) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_WIDTH) * row;
	z.re = p->jul_re + c.re;
	z.im = p->jul_im + c.im;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < p->iter)
	{
		tmp = z.re * z.re + z.im * z.im;
		if (tmp != 0)
		{
			z.re = z.re / tmp + c.re;
			z.im = -z.im / tmp + c.im;
		}
		iter++;
	}
	return (ft_color(p, iter));
}
