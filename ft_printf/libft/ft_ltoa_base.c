/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:19:20 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/04 15:25:52 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long long g_long_min;

static int		nbrlen(long long n, short base)
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
		n = n / base;
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

char			*ft_ltoa_base(long long n, short base)
{
	char			*str;
	unsigned int	d;
	int				len;
	unsigned int	sign;

	len = nbrlen(n, base);
	str = ft_strnew(len);
	if (!str)
		return (str);
	sign = 0;
	if (check_min_neg(&n, &sign))
		*(str + --len) = '8';
	while (len)
	{
		d = n % base;
		if (d >= 10)
			*(str + len - 1) = (char)('a' + d % 10);
		else
			*(str + len - 1) = (char)('0' + d);
		n = n / base;
		len--;
	}
	if (sign)
		*str = '-';
	return (str);
}
