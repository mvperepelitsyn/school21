/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:44:12 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/29 20:44:23 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_checker.h"
#include "libft.h"

int	is_flag(char c)
{
	if ((c == '-') || (c == '+') || (c == ' ') || (c == '#') || (c == '0'))
		return (1);
	else
		return (0);
}

int	is_size(char c)
{
	if ((c == 'l') || (c == 'h') || (c == 'j') || (c == 'z') || (c == 't')
	|| (c == 'L'))
		return (1);
	else
		return (0);
}

int	is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
	|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G'
	|| c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'S' || c == 'p'
	|| c == 'n' || c == 'U' || c == 'O' || c == 'D' || c == 'C')
		return (1);
	return (0);
}

int	is_valid(char c)
{
	if (is_type(c) || is_size(c) || is_flag(c) || ft_isdigit(c) ||
			(c == '.') || (c == '*'))
		return (1);
	return (0);
}

int	accumulate_digit(int *res, char c)
{
	int d;

	if (*res == -1)
		return (0);
	if (ft_isdigit(c) && c)
	{
		*res = *res * 10;
		d = (c - '0');
		*res += d;
		if (*res < 0)
		{
			*res = -1;
			return (0);
		}
		return (1);
	}
	return (0);
}
