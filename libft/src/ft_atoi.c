/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:47:45 by sstench           #+#    #+#             */
/*   Updated: 2019/09/22 15:11:28 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(size_t *num, int sign)
{
	if (*num > 9223372036854775807 && sign == 1)
		return (-1);
	else if (*num > 9223372036854775807 && sign == -1)
		return (0);
	if (sign >= 0)
		return (*num);
	else
		return (-*num);
}

int				ft_atoi(const char *str)
{
	size_t	index;
	size_t	result;
	int		sign;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index])
	{
		if (str[index] < 48 || str[index] > 57)
			return (result * sign);
		else
			result = (result * 10) + (long long int)(str[index] - '0');
		index++;
	}
	return (ft_check(&result, sign));
}
