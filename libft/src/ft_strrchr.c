/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:51:33 by sstench           #+#    #+#             */
/*   Updated: 2019/09/18 19:51:16 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char *str;

	str = (unsigned char *)s + ft_strlen(s);
	while (*str != (unsigned char)c)
	{
		if (str == (unsigned char *)s)
			return (NULL);
		str--;
	}
	return ((char *)str);
}
