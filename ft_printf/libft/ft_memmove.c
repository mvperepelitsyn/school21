/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:01:29 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 22:01:54 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*q;

	p = dest;
	q = src;
	if (q < p)
	{
		p += n;
		q += n;
		while (n)
		{
			*--p = *--q;
			n--;
		}
	}
	else if (p != q)
	{
		while (n)
		{
			*p++ = *q++;
			n--;
		}
	}
	return (dest);
}
