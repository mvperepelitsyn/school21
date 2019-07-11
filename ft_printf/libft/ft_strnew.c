/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:32:54 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:12:56 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*empty_str;
	size_t	i;

	empty_str = (char *)ft_memalloc(size + 1);
	if (empty_str == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		empty_str[i] = '\0';
		i++;
	}
	return (empty_str);
}
