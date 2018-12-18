/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:28:27 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/22 17:36:26 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void  ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_alphabet(void)
{
	char c;
	c = 97;
	while (c < 123)
	{
		ft_putchar(c);
		c = c + 1;
    }
	ft_putchar('\n');

}

int main()
{
    ft_print_alphabet();
	}
