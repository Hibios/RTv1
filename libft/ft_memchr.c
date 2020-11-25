/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:48:59 by sstench           #+#    #+#             */
/*   Updated: 2019/09/21 20:13:40 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*object;

	index = 0;
	object = (unsigned char *)s;
	while (index < n)
	{
		if (object[index] == (unsigned char)c)
			return (object + index);
		index++;
	}
	return (NULL);
}
