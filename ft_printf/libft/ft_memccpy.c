/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:44:15 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:44:19 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destptr, const void *srcptr, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)destptr;
	src = (unsigned char *)srcptr;
	while (n)
	{
		*dest = *src;
		dest++;
		if (*src == (unsigned char)c)
			return (dest);
		src++;
		n--;
	}
	return ((void *)0);
}
