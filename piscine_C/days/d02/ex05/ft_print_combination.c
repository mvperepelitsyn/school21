/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:04:00 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/23 09:16:22 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_putchar.c"

void ft_print_comb2(void)
{
	int a;
	int b;
	int desa;
	int eda;
	int desb;
	int edb;
	a = 00;
	b = 00;
	desa = a/10;
	eda = a%10;
	desb = b/10;
	edb = b%10;
	while (b<99)
	{
		b = b + 1;
		desb = b/10;
		edb = b&10;
		ft_putchar(desa+48);
        ft_putchar(eda+48);
        ft_putchar(44);
        ft_putchar(' ');
        ft_putchar(desb+48);
        ft_putchar(edb+48);
	}
}
int main()
{
	void ft_print_comb2();
}
