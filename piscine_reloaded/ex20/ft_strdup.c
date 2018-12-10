/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:36:23 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/11/24 13:07:38 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (src[x] != '\0')
	{
		dest[y] = src[x];
		x++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		n;
	char	*str;

	n = ft_strlen(src);
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
