/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:38:14 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/22 17:50:10 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void  ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_reverse_alphabet(void)
{ 
    char c;
    c = 123;
    while (c > 97)
    {
        c = c - 1;
		ft_putchar(c);
    }
    ft_putchar('\n');
}
int main()
{
    ft_print_reverse_alphabet();
}
