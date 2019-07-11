/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya8@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:36:45 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 21:46:46 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
