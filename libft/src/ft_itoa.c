/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:42:44 by sstench           #+#    #+#             */
/*   Updated: 2019/09/21 17:32:17 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isneg(int *num, int *neg)
{
	if (*num < 0)
	{
		*num *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		n_copy;
	int		negative;

	len = 2;
	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_isneg(&n, &negative);
	n_copy = n;
	while (n_copy /= 10)
		len++;
	len += negative;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
