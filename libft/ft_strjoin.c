/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:36:47 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:30:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < (ft_strlen(s1)))
			str[i] = s1[i];
		else
		{
			str[i] = s2[j];
			j++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
