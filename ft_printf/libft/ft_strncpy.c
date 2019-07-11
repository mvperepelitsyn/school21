/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:43:26 by variya            #+#    #+#             */
/*   Updated: 2018/12/15 21:47:53 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*res;

	if (n == 0)
		return (dest);
	res = dest;
	while (*src && n)
	{
		*res++ = *src++;
		n--;
	}
	while (n)
	{
		*res++ = '\0';
		n--;
	}
	return (dest);
}
