/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:21:46 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/26 18:21:49 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(char *dest, const char *src, unsigned int start, size_t len)
{
	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	while (dest[start] && *src && len)
	{
		dest[start] = *src;
		src++;
		start++;
		len--;
	}
	return (dest);
}
