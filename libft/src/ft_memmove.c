/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:31:46 by sstench           #+#    #+#             */
/*   Updated: 2019/09/22 13:58:23 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*from;
	const unsigned char	*to;

	if (dest == NULL && src == NULL)
		return (NULL);
	index = 0;
	from = (unsigned char *)dest;
	to = (unsigned char *)src;
	if (to < from)
		while (++index <= n)
			from[n - index] = to[n - index];
	else
		while (n-- > 0)
			*(from++) = *(to++);
	return (dest);
}
