/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:15:28 by variya            #+#    #+#             */
/*   Updated: 2018/12/16 13:39:48 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len_s2;

	len_s2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && n >= len_s2)
	{
		if (ft_strncmp(s1, s2, len_s2) == 0 && *s1 == *s2)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
