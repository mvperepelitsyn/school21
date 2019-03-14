/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:26:43 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/03/14 18:28:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		ft_checksym(char *str)
{
	size_t	i;
	size_t	count;
	size_t	count2;

	i = 0;
	count = 0;
	count2 = 0;
	while (i < 20 && (str[i] == '\n' || str[i] == '#' || str[i] == '.' ))
	{
		if (str[i] == '\n')
			count2++;
		if (str[i] == '#')
			count++;
		i++;
	}
	return ((/*str[i] == '\n' &&*/count2 == 4 && i == 20 && count == 4 && ft_checkconn(str) == 1) ? 1 : 0);
}
