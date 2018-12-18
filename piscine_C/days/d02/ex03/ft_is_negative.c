
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:56:01 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/22 19:22:05 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void  ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else 
	{
		ft_putchar('P');
	}
}
int main()
{
	ft_is_negative(-5);
}
