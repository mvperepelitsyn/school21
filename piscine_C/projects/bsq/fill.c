/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 20:40:43 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/11 20:44:32 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int		find(char *str, char c)
{
	int i;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned short get_elem(unsigned short **m, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	return (m[i][j]);
}
