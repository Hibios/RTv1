/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:50:03 by sstench           #+#    #+#             */
/*   Updated: 2019/09/18 19:16:49 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t index;
	size_t next;

	next = 0;
	index = 0;
	while (dest[index] != '\0')
		index++;
	while (src[next] != '\0')
	{
		dest[index + next] = src[next];
		next++;
	}
	dest[index + next] = '\0';
	return (dest);
}
