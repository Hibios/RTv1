/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:49:13 by sstench           #+#    #+#             */
/*   Updated: 2019/09/21 20:57:33 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*first;
	const unsigned char	*second;

	index = 0;
	first = (const unsigned char *)s1;
	second = (const unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (index < n)
	{
		if (first[index] != second[index])
			return ((int)first[index] - (int)second[index]);
		index++;
	}
	return (0);
}
