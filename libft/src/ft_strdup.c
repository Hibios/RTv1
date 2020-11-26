/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:34:25 by sstench           #+#    #+#             */
/*   Updated: 2019/09/22 13:53:58 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *new_str;

	new_str = (char *)malloc(ft_strlen(s1) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, s1);
	return (new_str);
}
