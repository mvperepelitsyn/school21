/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:23:37 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/11/28 21:37:35 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_hm_wrd(char const *s, char c)
{
	size_t	i;
	size_t	wrd;

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

static size_t	ft_begin(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_lwrd(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				len++;
				i++;
			}
			break ;
		}
		i++;
	}
	return (len);
}

static char		*ft_fwrd(char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_lwrd(s, c);
	str = (char*)malloc(sizeof(char) * (len + 1));
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				str[j] = s[i];
				j++;
				i++;
			}
			break ;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		beg;
	size_t		wrd;
	size_t		len;
	char		**ar;

	i = 0;
	beg = 0;
	len = 0;
	wrd = ft_hm_wrd(s, c);
	ar = (char**)malloc(sizeof(char) * (wrd + 1));
	while (i < wrd)
	{
		beg = ft_begin(s + beg, c) + beg;
		len = ft_lwrd(s, c);
		ar[i] = (char*)malloc(sizeof(char) * (len + 1));
		ar[i] = ft_fwrd(s, c);
		i++;
	}
	ar[i] = 0;
	return (ar);
}
