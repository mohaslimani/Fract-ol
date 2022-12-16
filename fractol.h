/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 23:31:51 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 22:16:57 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "complex.h"
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# define IMG_HEIGHT 500
# define MENU_H		450
# define MENU_W		300
# define IMG_WIDTH	500
# define NBTHRED	50
# define THRED_HEIGHT 10
# define FRACTAL 15
# define KEY_MINUS 78
# define KEY_PLUS 69
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_P 35
# define KEY_I 34
# define KEY_T 17
# define KEY_Y 16
# define KEY_W 13
# define KEY_Z 6
# define KEY_C 8
# define KEY_R 15
# define KEY_W 13
# define KEY_S 1
# define KEY_ESC 53
# define KEY_TAB 48
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef	struct	s_fractol
{
	int			type;
	int			color;
	void		*mlx;
	void		*win;
	void		*img_ptr;
	int			*img;
	int			bpp;
	int			sline;
	int			endian;
	void		*win2;
	int			order;
	long double	x_max;
	long double	x_min;
	long double	y_max;
	long double	y_min;
	int			iter;
	long double	zoom;
	long double	speed;
	int			pause;
	long double jul_re;
	long double jul_im;
	int			iter_sponge;
	long double zoom_s;
	char		*name;
	long double	moove_x;
	long double	moove_y;
	int			iter_s;
	long double	var;
}				t_fractol;

void			ft_fractol(t_fractol *data);
void			ft_draw(t_fractol *data);
int				julia(t_fractol *p, long double col, long double row);
int				deal_key(int key, t_fractol *data);
int				deal_x(int key, t_fractol *data);
int				mouse_wheel(int button, int x, int y, t_fractol *data);
void			ft_zoom(t_fractol *data, long double x, long double y,
long double k);
int				mouse_move(int x, int y, t_fractol *p);
int				sierpinski_carpet(t_fractol *e, int x, int y);
int				burningship(t_fractol *p, long double col, long double row);
int				burningship(t_fractol *p, long double col, long double row);
int				mandelbrot_1(t_fractol *p, long double col, long double row);
int				tricorn(t_fractol *p, long double col, long double row);
int				quadcorne(t_fractol *p, long double col, long double row);
int				negative_mandelbrot(t_fractol *p, long double col,
long double row);
int				fake_quadcorne(t_fractol *p, long double col, long double row);
int				quint_corne(t_fractol *p, long double col, long double row);
int				fake_sext_corne(t_fractol *p, long double col, long double row);
void			control(t_fractol *data);
int				mandelbrot(t_fractol *data, long double col, long double row);
int				multibrot_2(t_fractol *data, long double col, long double row);
int				multibrot_3(t_fractol *data, long double col, long double row);
int				multibrot_4(t_fractol *data, long double col, long double row);
int				negative_mandelbrot_1(t_fractol *p, long double col,
long double row);
int				negative_mandelbrot_2(t_fractol *p, long double col,
long double row);
int				sierpinski_triangle(t_fractol *data, long double col,
long double row);
void			square_fill(t_fractol *data, int color, t_coord pos,
t_coord size);
void			put_pixel(t_fractol *data, int x, int y, int color);
int				rorscharch(t_fractol *p, long double col, long double row);
int				sphere(t_fractol *data, long double col, long double row);
int				ft_color(t_fractol *p, int iter);
char			*init_name(t_fractol *data);
void			ctrl_name(t_fractol *data);
int				ft_color_5(t_fractol *data, int iter);
int				ft_color_6(t_fractol *data, int iter);
int				ft_color_7(t_fractol *data, int iter);
int				ft_color_8(t_fractol *data, int iter);
int				ft_color_9(t_fractol *data, int iter);
#endif
