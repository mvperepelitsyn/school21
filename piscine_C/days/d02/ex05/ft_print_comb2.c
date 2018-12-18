/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:17:54 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/23 08:57:47 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_putchar.c"

void ft_print_comb2(void)
{
	int a;
	int b;
	int c;
	int d;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (d<11)
	{
		d = d + 1;
		ft_putchar(a+48);
		ft_putchar(b+48);
		ft_putchar(44);
		ft_putchar(' ');
		ft_putchar(c+48);
        ft_putchar(d+48);
		if (d==10)
		{
		c = c + 1;
		ft_putchar(a+48);
        ft_putchar(b+48);
        ft_putchar(44);
        ft_putchar(' ');
		ft_putchar(c+48);
        ft_putchar(48);
		}
	}



}
int main()
{
	void ft_print_comb2();
}
