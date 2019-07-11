/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya8@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:57:06 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/16 13:40:22 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int					ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || \
			c == '\b' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static unsigned long int	str_to_nbr(const char *s, int is_neg)
{
	unsigned long int	res;

	res = 0;
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		if (res >= 9223372036854775807 && is_neg == 0)
			return (-1);
		else if (res > 9223372036854775807 && is_neg == 1)
			return (0);
		s++;
	}
	if (is_neg)
		res = -res;
	return (res);
}

int							ft_atoi(const char *nptr)
{
	const char	*s;
	int			is_neg;

	if (*nptr == '\e')
		return (0);
	s = nptr;
	while (ft_isspace(*s) || *s == '0')
		s++;
	if (*s == '-')
	{
		is_neg = 1;
		s++;
	}
	else
	{
		is_neg = 0;
		if (*s == '+')
			s++;
	}
	return ((int)(str_to_nbr(s, is_neg)));
}
