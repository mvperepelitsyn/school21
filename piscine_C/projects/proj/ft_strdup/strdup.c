/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:00:59 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/13 13:09:30 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i++])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
