/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:19:20 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/04 15:27:07 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nbrlen(unsigned long long n)
{
	int	len;

	len = 0;
	while (1)
	{
		n = n / 10;
		len++;
		if (n == 0)
			break ;
	}
	return (len);
}

char		*ft_ultoa(unsigned long long n)
{
	char	*str;
	int		len;

	len = nbrlen(n);
	str = ft_strnew(len);
	if (!str)
		return (str);
	while (len)
	{
		*(str + len - 1) = (char)('0' + n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}
