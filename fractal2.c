/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:03:43 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 18:54:07 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		negative_mandelbrot_2(t_fractol *p, long double col, long double row)
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
		tmp = z.re;
		z.re = (z.re * z.re - z.im * z.im) / (z.re * z.re * z.re * z.re
				+ z.im * z.im * z.im * z.im + 2 * z.re * z.re * z.im * z.im)
			+ c.re;
		z.im = -(2 * tmp * z.im) / (tmp * tmp * tmp * tmp + z.im * z.im *
				z.im * z.im + 2 * tmp * tmp * z.im * z.im) + c.im;
		iter++;
	}
	return (ft_color(p, iter));
}

int		julia(t_fractol *p, long double col, long double row)
{
	int				iter;
	t_complex		z;
	t_complex		c;
	long double		tmp;

	z.re = p->x_min + ((p->x_max - p->x_min) / IMG_WIDTH) * col;
	z.im = p->y_min + ((p->y_max - p->y_min) / IMG_WIDTH) * row;
	c.re = p->jul_re;
	c.im = p->jul_im;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < p->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_color(p, iter * 20));
}

int		sierpinski_carpet(t_fractol *data, int x, int y)
{
	int				i;
	long double		a;
	long double		b;

	i = 1;
	a = (long double)x;
	b = (long double)y;
	while (i < data->iter_sponge)
	{
		a = ((float)x + data->moove_x)
		* data->zoom * (pow(3, i) / (float)IMG_HEIGHT) + 1;
		b = ((float)y + data->moove_y)
		* data->zoom * (pow(3, i) / (float)IMG_WIDTH) + 1;
		((int)a > 3) ? (a = ((int)a % 3)) : 0;
		((int)b > 3) ? (b = ((int)b % 3)) : 0;
		if (a == b && a == 0)
		{
			a += 1;
			b += 1;
		}
		if (a > 0 && b > 0 && 3 % (int)a == 1 && 3 % (int)b == 1)
			return (0x000000);
		i++;
	}
	return (ft_color(data, 100));
}

int		sierpinski_triangle(t_fractol *data, long double col, long double row)
{
	t_coord a;

	a.x = (((float)data->iter_s / (float)IMG_HEIGHT) * col)
	* data->zoom_s + data->moove_x;
	a.y = (((float)data->iter_s / (float)IMG_WIDTH) * row)
	* data->zoom_s + data->moove_y;
	if (a.x & a.y)
		return (0x000000);
	return (ft_color(data, 100));
}

int		tricorn(t_fractol *p, long double col, long double row)
{
	int				iter;
	t_complex		z;
	t_complex		c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_WIDTH) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_WIDTH) * row;
	z.re = p->jul_re;
	z.im = p->jul_im;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < p->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = -1 * 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_color(p, iter));
}
