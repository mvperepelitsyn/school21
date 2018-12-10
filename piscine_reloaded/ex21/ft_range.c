/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:15:56 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/11/24 13:17:33 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int range;
	int *int_array;
	int i;

	i = 0;
	range = max - min;
	if (min >= max)
		return (NULL);
	int_array = (int*)malloc(sizeof(int) * (range + 1));
	while (min < max)
	{
		int_array[i] = min;
		i++;
		min++;
	}
	int_array[i] = '\0';
	return (int_array);
}
