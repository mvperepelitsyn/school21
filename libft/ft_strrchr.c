/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:44:06 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/10 15:30:57 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = ft_strlen(s);
	if (i == 0)
		return (NULL);
	while (str[i] != c && i >= 0)
		i--;
	if (i < 0)
		return (NULL);
	return (str + i);
}
