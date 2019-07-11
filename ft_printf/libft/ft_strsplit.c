/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:38:28 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:42:10 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int		count_words(char const *s, char c)
{
	unsigned int		is_word;
	unsigned int		count;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!is_word)
				count++;
			is_word = 1;
		}
		else
			is_word = 0;
		s++;
	}
	return (count);
}

static unsigned int		substr_len(char const *str, char c)
{
	unsigned int		len;

	len = 0;
	while (*str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static void				*ft_clear(char ***s)
{
	while (**s)
	{
		free(**s);
		s++;
	}
	free(*s);
	return (NULL);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**splits;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (!(splits = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = -1;
	while (++i < count)
	{
		while (*s == c)
			s++;
		len = substr_len(s, c);
		if (!(splits[i] = ft_strnew(len)))
			return (ft_clear(&splits));
		j = -1;
		while (++j < len)
			splits[i][j] = *s++;
	}
	splits[i] = 0;
	return (splits);
}
