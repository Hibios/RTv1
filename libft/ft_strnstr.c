/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:51:22 by sstench           #+#    #+#             */
/*   Updated: 2019/09/18 19:47:35 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t size2;

	if (*s2 == '\0')
		return ((char *)s1);
	size2 = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= size2)
	{
		if (*s1 != '\0' && ft_memcmp(s1, s2, size2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
