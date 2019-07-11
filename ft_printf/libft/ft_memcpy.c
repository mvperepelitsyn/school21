/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:44:34 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:44:38 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	char		*dest;
	const char	*src;

	dest = destptr;
	src = srcptr;
	while (num)
	{
		*dest++ = *src++;
		num--;
	}
	return (destptr);
}
