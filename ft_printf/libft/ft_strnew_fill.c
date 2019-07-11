/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:02:47 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 17:02:51 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnew_fill(size_t size, char filler)
{
	char	*empty_str;
	size_t	i;

	empty_str = (char *)ft_memalloc(size + 1);
	if (empty_str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		empty_str[i] = filler;
		i++;
	}
	empty_str[i] = '\0';
	return (empty_str);
}
