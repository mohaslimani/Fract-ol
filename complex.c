/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 02:26:13 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/28 00:45:46 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

long	double		mod_carre_complex(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}
