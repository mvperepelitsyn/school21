/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <dfrost-a@student.21.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:48:07 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/26 21:11:20 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(char left, char middle, char right, int length)
{
	int	i;

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

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	print_row('\/', '*', '\\', x);
	if (y > 2)
	{
		i = 1;
		while (i++ < y - 1)
			print_row('*', ' ', '*', x);
	}
	if (y >= 2)
		print_row('\\', '*', '\/', x);
}
