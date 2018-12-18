/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:29:51 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/13 12:54:42 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (srcs[i++])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
