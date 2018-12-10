/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:23:37 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/02 18:18:28 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_lentill(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

static int		ft_hm_wrd(char const *s, char c)
{
	size_t	i;
	int		wrd;

	i = 0;
	wrd = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			wrd++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (wrd);
}

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
