/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:45:21 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:45:25 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*c;

	c = memptr;
	while (num)
	{
		*c = val;
		num--;
		c++;
	}
	return (memptr);
}
