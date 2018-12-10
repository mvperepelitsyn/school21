/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:25:37 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/06 18:43:12 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	len;
	size_t	slen;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	j = 0;
	slen = ft_strlen(src);
	while (dst[i] && size > 0)
	{
		i++;
		len++;
		size--;
	}
	while (size-- > 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size == 1 || src[j] == '\0')
		dst[i] = '\0';
	return (slen + len);
}
