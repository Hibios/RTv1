/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnedu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:53:08 by sstench           #+#    #+#             */
/*   Updated: 2020/08/11 10:50:21 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (s1 && s2 && n > 0)
	{
		while (s1[index] && s2[index] && s1[index] == s2[index])
		{
			if ((index + 1) == n)
				break ;
			index++;
		}
		if (s1[index] != s2[index])
			return (0);
	}
	return (1);
}
