/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:51:33 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:51:37 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*end;

	end = s + ft_strlen(s);
	while (1)
	{
		if (*end == c)
			return ((char *)end);
		if (end == s)
			return ((void *)0);
		end--;
	}
	return ((void *)0);
}
