/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:49:56 by sstench           #+#    #+#             */
/*   Updated: 2020/11/25 18:49:57 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec	vec_scale(t_vec v, double nb)
{
	v.x *= nb;
	v.y *= nb;
	v.z *= nb;
	return (v);
}
