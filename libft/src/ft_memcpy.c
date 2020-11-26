/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:49:27 by sstench           #+#    #+#             */
/*   Updated: 2019/09/18 20:22:30 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	if (dest == NULL && src == NULL)
		return (NULL);
	index = 0;
	buffer1 = (unsigned char *)dest;
	buffer2 = (unsigned char *)src;
	while (index < n)
	{
		buffer1[index] = buffer2[index];
		index++;
	}
	return (dest);
}
