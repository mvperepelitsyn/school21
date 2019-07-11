/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:58:52 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 21:13:23 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "extract.h"
#include <stddef.h>
#include <stdint.h>

/*
** This function transform integer number to string in
** decimal/octal/hexadecimal system depending on its size.
*/

char		*extract_int(t_format *arg_format, va_list ap, short base)
{
	char	*str;

	if (arg_format->size == 'h')
		str = ft_itoa_base((short int)va_arg(ap, int), base);
	else if (arg_format->size == 'H')
		str = ft_itoa_base((signed char)va_arg(ap, int), base);
	else if (arg_format->size == 'l')
		str = ft_ltoa_base((va_arg(ap, long int)), base);
	else if (arg_format->size == 'I')
		str = ft_ltoa_base(va_arg(ap, long long int), base);
	else if (arg_format->size == 'j')
		str = ft_ltoa_base(va_arg(ap, intmax_t), base);
	else if (arg_format->size == 'z')
		str = ft_ltoa_base(va_arg(ap, size_t), base);
	else if (arg_format->size == 't')
		str = ft_ltoa_base(va_arg(ap, ptrdiff_t), base);
	else if (arg_format->size == 'L')
		str = ft_ltoa_base(va_arg(ap, int), base);
	else
		str = ft_itoa_base(va_arg(ap, int), base);
	return (str);
}

/*
** This function transform unsigned integer number to string in
** decimal/octal/hexadecimal system depending on its size.
*/

char		*extract_uint(t_format *arg_format, va_list ap, short base)
{
	char	*str;

	if (arg_format->type == 'U')
		str = ft_ultoa_base(va_arg(ap, unsigned long long int), base);
	else if (arg_format->type == 'p')
		str = ft_ultoa_base(va_arg(ap, unsigned long long int), base);
	else if (arg_format->size == 'h')
		str = ft_ultoa_base((unsigned short int)va_arg(ap, unsigned int), base);
	else if (arg_format->size == 'H')
		str = ft_ultoa_base((unsigned char)va_arg(ap, unsigned int), base);
	else if (arg_format->size == 'l')
		str = ft_ultoa_base(va_arg(ap, unsigned long int), base);
	else if (arg_format->size == 'I')
		str = ft_ultoa_base(va_arg(ap, unsigned long long int), base);
	else if (arg_format->size == 'j')
		str = ft_ultoa_base((uintmax_t)va_arg(ap, unsigned long long int), \
				base);
	else if (arg_format->size == 'z')
		str = ft_ultoa_base((size_t)va_arg(ap, unsigned long long int), base);
	else if (arg_format->size == 't')
		str = ft_ultoa_base((ptrdiff_t)va_arg(ap, unsigned long long int), \
		base);
	else
		str = ft_ultoa_base(va_arg(ap, unsigned int), base);
	return (str);
}

void		change_nullnumber(char *str, t_format *arg_format)
{
	int k;

	if (str != NULL)
	{
		k = ft_strlen(str);
		str[0] = ((str[0] == '0' && k == 1 && arg_format->precision == 0) &&
		(arg_format->type != 'o' || (arg_format->type == 'o' && arg_format->
		flag[spacial] == '0'))) ? '\0' : str[0];
	}
}

/*
** This function make string from number in right format.
*/

char		*extract_number(t_format *arg_format, va_list ap)
{
	char	*str;

	str = NULL;
	if (arg_format->type == 'i' || arg_format->type == 'd')
		str = extract_int(arg_format, ap, DEC_BASE);
	if ((arg_format->type == 'u') || (arg_format->type == 'U'))
		str = extract_uint(arg_format, ap, DEC_BASE);
	if (arg_format->type == 'o' || arg_format->type == 'O')
		str = extract_uint(arg_format, ap, OCT_BASE);
	if ((arg_format->type == 'x') || (arg_format->type == 'X') || \
		arg_format->type == 'p')
	{
		str = extract_uint(arg_format, ap, HEX_BASE);
		if (arg_format->type == 'X')
			ft_strupper(str);
	}
	change_nullnumber(str, arg_format);
	return (str);
}
