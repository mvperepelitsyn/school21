/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:23:37 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/13 22:00:18 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	size_t		j;
	size_t		l;
	char		**ar;

	i = -1;
	if (!s || !(ar = (char**)malloc(sizeof(char*) * (ft_hm_wrd(s, c) + 1))))
		return (NULL);
	l = 0;
	while (++i < (ft_hm_wrd((char*)s, c)))
	{
		j = 0;
		if (!(ar[i] = ft_strnew(ft_lentill(s + l, c) + 1)))
			ar[i] = NULL;
		while (s[l] == c)
			l++;
		while (s[l] != c && s[l])
			ar[i][j++] = s[l++];
		ar[i][j] = '\0';
	}
	ar[i] = 0;
	return (ar);
}
