/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:34:22 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/01 13:38:39 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*f;
	size_t	i;

	f = malloc(size);
	i = 0;
	if (f == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)f)[i] = 0;
		i++;
	}
	return (f);
}
