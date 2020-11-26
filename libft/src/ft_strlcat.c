/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:50:30 by sstench           #+#    #+#             */
/*   Updated: 2019/09/18 19:41:53 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;
	size_t dst_size;
	size_t src_size;

	index = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (src_size + size);
	while ((dst[index] != '\0') && index < (size - 1))
		index++;
	while (*src && index < (size - 1))
	{
		dst[index] = *src;
		index++;
		src++;
	}
	dst[index] = '\0';
	return (dst_size + src_size);
}
