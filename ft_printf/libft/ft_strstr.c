/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:07:18 by variya            #+#    #+#             */
/*   Updated: 2018/12/15 21:53:12 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	const char		*begin_str1;
	const char		*begin_str2;

	if (*str2 == '\0')
		return ((char *)str1);
	begin_str2 = str2;
	while (*str1)
	{
		begin_str1 = str1;
		while (*str1 == *str2 && *str2)
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
			return ((char *)begin_str1);
		str1 = begin_str1;
		str2 = begin_str2;
		str1++;
	}
	return ((void *)0);
}
