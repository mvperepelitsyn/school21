/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:13:47 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:19:51 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char const		*start;
	char const		*end;
	char			*new;
	char			*begin;

	if (!s)
		return ((void *)(0));
	start = s;
	end = s + ft_strlen(s) - 1;
	while (is_space(*start))
		start++;
	while (is_space(*end) && ft_strlen(start) != 0)
		end--;
	new = ft_strnew(end - start + 1);
	if (!new)
		return (new);
	begin = new;
	while (start <= end)
	{
		*new = *start;
		new++;
		start++;
	}
	return (begin);
}
