/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:09:00 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 17:14:48 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_replace(const char *s, char a, char b)
{
	char const	*c;

	if (!s)
		return ;
	c = s;
	while (*c)
	{
		if (*c == a)
			write(1, &b, 1);
		else
			write(1, c, 1);
		c++;
	}
}
