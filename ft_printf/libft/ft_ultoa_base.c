/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:19:20 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/04 15:27:27 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nbrlen(unsigned long long n, short base)
{
	int	len;

	len = 0;
	while (1)
	{
		n = n / base;
		len++;
		if (n == 0)
			break ;
	}
	return (len);
}

char		*ft_ultoa_base(unsigned long long n, short base)
{
	char			*str;
	unsigned int	d;
	int				len;

	len = nbrlen(n, base);
	str = ft_strnew(len);
	if (!str)
		return (str);
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
	return (str);
}
