/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:50:49 by variya            #+#    #+#             */
/*   Updated: 2018/12/15 21:48:35 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *destptr, const char *src, size_t n)
{
	char	*dest;

	dest = destptr;
	while (*dest)
		dest++;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = '\0';
	return (destptr);
}
