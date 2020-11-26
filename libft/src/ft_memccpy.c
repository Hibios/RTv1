/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:48:39 by sstench           #+#    #+#             */
/*   Updated: 2019/09/18 19:56:08 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*from;
	unsigned char	*to;

	index = 0;
	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	while (index < n)
	{
		to[index] = from[index];
		if (from[index] == (unsigned char)c)
			return (dest + index + 1);
		index++;
	}
	return (NULL);
}
