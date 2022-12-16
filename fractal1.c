/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:03:40 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 18:07:23 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		quadcorne(t_fractol *p, long double col, long double row)
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
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_color(p, iter));
}

int		quint_corne(t_fractol *p, long double col, long double row)
{
	int				iter;
	t_complex		z;
	t_complex		c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_WIDTH) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_WIDTH) * row;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (mod_carre_complex(z) <= 4 && iter < p->iter)
	{
		tmp = z.re;
		z.re = z.re * z.re * z.re * z.re + z.im * z.im * z.im * z.im -
		6 * z.re * z.re * z.im * z.im + c.re;
		z.im = -4 * tmp * tmp * tmp * z.im +
		4 * tmp * z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_color(p, iter));
}

int		burningship(t_fractol *p, long double col, long double row)
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
		if (z.re < 0)
			z.re *= -1.0;
		if (z.im < 0)
			z.im *= -1.0;
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * (tmp) * (z.im) + c.im;
		iter++;
	}
	return (ft_color(p, iter));
}

int		rorscharch(t_fractol *p, long double col, long double row)
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
		tmp = (z.re < 0) ? -z.re : z.re;
		z.re = z.re * z.re - z.im * z.im - c.re;
		z.im = (2 * z.im) * tmp - c.im;
		iter += 1;
	}
	return (ft_color(p, iter));
}

int		sphere(t_fractol *data, long double col, long double row)
{
	t_complex			z;
	t_complex			c;
	long double			tmp;
	int					iter;

	iter = 0;
	c.re = 0.139375 + data->jul_re;
	c.im = -0.89250 + data->jul_im;
	z.re = data->x_min + ((data->x_max - data->x_min) / IMG_WIDTH) * col;
	z.im = data->y_min + ((data->y_max - data->y_min) / IMG_WIDTH) * row;
	while (mod_carre_complex(z) < data->var && iter < data->iter)
	{
		tmp = (z.re < 0) ? -z.re : z.re;
		z.im = (z.im < 0) ? -z.im : z.im;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = z.im * tmp + c.im;
		iter++;
	}
	return (ft_color(data, iter));
}
