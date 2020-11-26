/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:53:41 by sstench           #+#    #+#             */
/*   Updated: 2020/11/25 17:53:42 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_valid_vec(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '.' && *str != ',')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_nb(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '.')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_hex(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		if (!ft_isdigit(*str) && (*str < 'a' || *str > 'f'))
			return (0);
		str++;
	}
	return (1);
}
