/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_xyz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:56:51 by sstench           #+#    #+#             */
/*   Updated: 2020/11/25 19:56:52 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec		vec_rot_xyz(t_vec v, t_vec r)
{
	v = vec_rot_x(v, vec_dtr(r.x));
	v = vec_rot_y(v, vec_dtr(r.y));
	v = vec_rot_z(v, vec_dtr(r.z));
	return (v);
}
