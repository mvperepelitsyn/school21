/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:28:32 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/13 12:07:49 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int numb;

	i = 0;
	numb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		numb = (numb * 10) + str[i] - 48;
		i++;
	}
	numb = numb * sign;
	return (numb);
}

int		main(void)
{
	const char a[] = "       \n\t\n\v\r\f wd-12412awdawdw";
	int i;
	i = ft_atoi(a);
	printf("%d\n", i);
	return (0);
}
