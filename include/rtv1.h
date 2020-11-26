/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:01:56 by sstench           #+#    #+#             */
/*   Updated: 2020/11/25 15:01:57 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "rtv1types.h"

# define WNDW		1080
# define WNDW_H		540
# define WNDH		720
# define WNDH_H		360
# define FOV		60.0
# define FOV_H		30
# define PPD		935

double			t_sphere(t_ray *r, t_obj sphere);
double			col_sphere(t_ray r, t_rgb *col, int id, void *env);

double			t_cylinder(t_ray *r, t_obj cylinder);
double			col_cylinder(t_ray r, t_rgb *col, int id, void *env);

double			t_plane(t_ray *r, t_obj plane);
double			col_plane(t_ray r, t_rgb *col, int id, void *env);

double			t_cone(t_ray *r, t_obj ccone);
double			col_cone(t_ray r, t_rgb *col, int id, void *env);

double			get_t(double a, double b, double d);
unsigned int	get_color(t_ray r, int id, t_env *env);

void			trace_ray(t_ray *r, t_env env);
void			init_ray(t_ray *r, t_env env);
int				find_closest(t_ray r, t_env env);
void			comp_ray(t_ray *r, t_vec n, double t);

void			put_error(char *str);
void			free_double_string(char **sl);

#endif
