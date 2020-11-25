/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:51:48 by sstench           #+#    #+#             */
/*   Updated: 2019/09/19 13:34:38 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t index;
	size_t size;
	size_t pos;

	index = 0;
	size = 0;
	pos = 0;
	while (needle[index] != '\0')
		index++;
	if (index == 0)
		return ((char *)haystack);
	while (haystack[size])
	{
		while (needle[pos] == haystack[size + pos])
		{
			if (pos == index - 1)
				return ((char *)haystack + size);
			pos++;
		}
		pos = 0;
		size++;
	}
	return (0);
}
