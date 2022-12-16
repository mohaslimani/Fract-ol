/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 02:20:18 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/28 00:45:43 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef	struct	s_complex
{
	long double	re;
	long double im;
}				t_complex;

long double		mod_carre_complex(t_complex z);
#endif
