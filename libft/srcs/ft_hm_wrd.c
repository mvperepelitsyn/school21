/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hm_wrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:46:56 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/13 21:58:20 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_hm_wrd(char const *s, char c)
{
	size_t	i;
	int		wrd;

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
