/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:42:29 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/01 17:36:03 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_hm_ws(char const *s)
{
	size_t	i;
	size_t	n;
	size_t	k;

	i = 0;
	n = 0;
	k = ft_strlen(s);
	while (s[i++])
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
			break ;
	n = i;
	if (i == (k + 1))
		return (0);
	while (k > 0)
	{
		if (s[k] != ' ' && s[k] != '\n' && s[k] != '\t' && s[k] != '\0')
			break ;
		k--;
	}
	k = k - n + 1;
	return (k);
}

static	size_t	till(char const *s)
{
	size_t k;

	k = ft_strlen(s);
	while (k > 0)
	{
		if (s[k] != ' ' && s[k] != '\n' && s[k] != '\t' && s[k] != '\0')
			break ;
		k--;
	}
	return (k);
}

static	char	*iwannadie(char const *s, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
		{
			while (i <= (till(s)))
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

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(char) * (ft_hm_ws(s) + 1));
	if (str == NULL)
		return (NULL);
	if ((till(s)) == 0)
		return ("\0");
	str = iwannadie(s, str);
	return (str);
}
