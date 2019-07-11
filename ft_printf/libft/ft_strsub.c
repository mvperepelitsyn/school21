/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:59:55 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:18:34 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	char	*c;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	sub_str = (char *)ft_strnew(len);
	if (sub_str == NULL)
		return (NULL);
	c = sub_str;
	while (start)
	{
		s++;
		start--;
	}
	while (*s && len)
	{
		*c = *s;
		s++;
		c++;
		len--;
	}
	return (sub_str);
}
