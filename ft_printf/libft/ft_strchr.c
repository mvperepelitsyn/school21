/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:51:46 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:51:48 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *str;

	str = s;
	while (1)
	{
		if (*str == c)
			return ((char *)str);
		if (*str == '\0')
			return ((void *)0);
		str++;
	}
	return ((void *)0);
}
