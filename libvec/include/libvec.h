/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:02:44 by sstench           #+#    #+#             */
/*   Updated: 2020/11/25 17:54:38 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

# define DTR(k)	((double)k * (M_PI / 180))

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

t_vec			vec_new(double x, double y, double z);
t_vec			vec_scale(t_vec v, double nb);
t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec a, t_vec b);
double			vec_magn(t_vec v);
t_vec			vec_norm(t_vec v);
t_vec			vec_cpy(t_vec v);

double			vec_dot(t_vec a, t_vec b);
t_vec			vec_cross(t_vec a, t_vec b);

/*
**	Applies counterclockwise rotations about axes for angle of a rad.
*/

t_vec			vec_rot_x(t_vec v, double a);
t_vec			vec_rot_y(t_vec v, double a);
t_vec			vec_rot_z(t_vec v, double a);
t_vec			vec_rot_xyz(t_vec v, t_vec r);
t_vec			vec_rot_zyx(t_vec v, t_vec r);

#endif
