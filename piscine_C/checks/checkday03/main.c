/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:00:03 by amerlon-          #+#    #+#             */
/*   Updated: 2018/08/25 17:16:32 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_row(char left, char middle, char right, int length)
{
    int    i;
    
    ft_putchar(left);
    if (length > 2)
    {
        i = 1;
        while (i++ < length - 1)
            ft_putchar(middle);
    }
    if (length >= 2)
        ft_putchar(right);
    ft_putchar('\n');
}

void    rush(int x, int y)
{
    int    i;
    
    if (x <= 0 || y <= 0)
        return ;
    print_row('/', '*', '\\', x);
    if (y > 2)
    {
        i = 1;
        while (i++ < y - 1)
            print_row('*', ' ', '*', x);
    }
    if (y >= 2)
        print_row('\\', '*', '/', x);
}

int		main(void)
{
	rush(0, 42);
	return (0);
}
