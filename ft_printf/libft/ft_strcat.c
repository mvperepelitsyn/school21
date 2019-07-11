/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: variya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:45:59 by variya            #+#    #+#             */
/*   Updated: 2018/12/15 21:48:16 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *src)
{
	char	*dest;

	dest = destptr;
	while (*dest)
		dest++;
	ft_strcpy(dest, src);
	return (destptr);
}
