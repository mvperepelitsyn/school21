/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya8@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:53:39 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:55:23 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	if (num == 0)
		return (0);
	while (*s1 == *s2 && num && *s1)
	{
		num--;
		s1++;
		s2++;
	}
	if (num == 0)
	{
		s1--;
		s2--;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
