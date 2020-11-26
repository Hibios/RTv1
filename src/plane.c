/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:53:15 by sstench           #+#    #+#             */
/*   Updated: 2020/11/25 17:53:16 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libvec.h"

t_vec		vec_plane_n(t_ray r, t_obj plane)
{
	if (vec_dot(r.dir, plane.v) < 0)
		return (plane.v);
	return (vec_scale(plane.v, -1));
}

double		t_plane(t_ray *r, t_obj plane)
{
	double	t;
	double	a;
	double	b;

	a = vec_dot(vec_sub(r->start, plane.pos), plane.v);
	b = vec_dot(r->dir, plane.v);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	return (t > 0 ? t : -1);
}

double		col_plane(t_ray r, t_rgb *col, int id, void *env)
{
	double	t;
	t_obj	plane;

	plane = ((t_env*)env)->obj[id];
	t = t_plane(&r, plane);
	if (t > 0)
	{
		comp_ray(&r, vec_plane_n(r, plane), t);
		col->c = get_color(r, id, (t_env*)env);
	}
	return (t);
}
