/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:19:20 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/04 15:24:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long long g_long_min;

static int		nbrlen(long long n)
{
	int	len;

	len = 0;
	g_long_min = -9223372036854775807 - 1;
	if (n == g_long_min)
		return (20);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (1)
	{
		n = n / 10;
		len++;
		if (n == 0)
			break ;
	}
	return (len);
}

static int		check_min_neg(long long *n, unsigned int *sign)
{
	unsigned int	flag;

	flag = 0;
	if (*n < 0)
	{
		*sign = 1;
		if (*n == g_long_min)
		{
			*n = *n / 10;
			flag = 1;
		}
		*n = -(*n);
	}
	return (flag);
}

char			*ft_ltoa(long long n)
{
	char			*str;
	int				len;
	unsigned int	sign;

	len = nbrlen(n);
	str = ft_strnew(len);
	if (!str)
		return (str);
	sign = 0;
	if (check_min_neg(&n, &sign))
		*(str + --len) = '8';
	while (len)
	{
		*(str + len - 1) = (char)('0' + n % 10);
		n = n / 10;
		len--;
	}
	if (sign)
		*str = '-';
	return (str);
}
