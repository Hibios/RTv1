/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:52:46 by sstench           #+#    #+#             */
/*   Updated: 2020/11/26 15:15:10 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "parser.h"

void	parse_light(t_light *light, char **sl)
{
	int nberr;

	if (!sl[1])
		parse_error(NOT_ENOUGH_DATA);
	nberr = get_vec_data(&light->pos, sl[1]);
	parse_error(nberr);
	if (!sl[2])
		parse_error(NOT_ENOUGH_DATA);
	if (!is_valid_nb(sl[2]))
		parse_error(WRONG_CHARACTER);
	light->intensity = ft_atoi(sl[2]);
	if (light->intensity < 0)
		light->intensity = 0;
	else if (light->intensity > 100)
		light->intensity = 100;
	light->intensity /= 100;
	light->col.bgra[0] = 0xff * light->intensity;
	light->col.bgra[1] = 0xff * light->intensity;
	light->col.bgra[2] = 0xff * light->intensity;
}

void	parse_ambient(t_env *env, char **sl)
{
	env->total_light -= env->ambient.intensity;
	if (!sl[1])
		parse_error(NOT_ENOUGH_DATA);
	if (!is_valid_nb(sl[1]))
		parse_error(WRONG_CHARACTER);
	env->ambient.intensity = ft_atoi(sl[1]);
	if (env->ambient.intensity < 0)
		env->ambient.intensity = 0;
	else if (env->ambient.intensity > 100)
		env->ambient.intensity = 100;
	env->ambient.intensity /= 100;
	env->ambient.col.bgra[0] = 0xff * env->ambient.intensity;
	env->ambient.col.bgra[1] = 0xff * env->ambient.intensity;
	env->ambient.col.bgra[2] = 0xff * env->ambient.intensity;
	env->total_light += env->ambient.intensity;
}

void	light_push_back(t_env *env, char **sl)
{
	t_light	lt;
	t_light	*tmp;
	int		i;

	parse_light(&lt, sl);
	tmp = env->light;
	if (!(env->light = (t_light*)malloc(sizeof(t_light) *
		(env->lightcount + 1))))
		put_error("Light memory allocation fail");
	i = -1;
	while (++i < env->lightcount)
		light_cpy(tmp[i], &env->light[i]);
	light_cpy(lt, &env->light[i]);
	env->lightcount += 1;
	env->total_light += lt.intensity;
	free(tmp);
}
