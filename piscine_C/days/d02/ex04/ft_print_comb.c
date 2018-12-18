/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:33:41 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/22 20:32:35 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_putchar.c"

void ft_print_comb(void)
{
	int n;
    int sot;
    int des;
    int ed;
	n = 012;
	sot = n/100;
	des = (n%100)/10;
	ed = n%10;

	while (n < 789)
	{
		n = n + 1;
		sot = n/100;
		des = (n%100)/10;
		ed = n%10;
		if ((sot<des) && (des <ed))
		{
			ft_putchar(sot + 48);
			ft_putchar(des + 48);
			ft_putchar(ed + 48);
			ft_putchar(' ');
		}
	}
}

int main()
{
	ft_print_comb();
}
