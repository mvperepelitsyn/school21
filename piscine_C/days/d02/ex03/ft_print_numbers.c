/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:58:24 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/22 18:31:06 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}
void ft_print_numbers(void)
{
	char c;
	c = 47;
	while (c < 57)
	{
		c= c + 1;
		ft_putchar(c);
	}
	ft_putchar('\n');
}
int main()
{
	ft_print_numbers();
}
