/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:25:37 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/10 19:28:07 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	ld;
	int		i;

	i = 0;
	ld = ft_strlen(dst);
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dlen + 1 > size)
		return (slen + size);
	if (dlen + 1 < size)
	{
		while (ld < size - 1)
			*(dst + ld++) = *(src + i++);
		dst[ld] = '\0';
	}
	return (slen + dlen);
}
