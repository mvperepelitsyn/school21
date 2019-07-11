/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 18:38:57 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 21:04:13 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "extract.h"

/*
** How many bytes?
** code             bytes
** 0-127            1
** 128-2047 	    2
** 2048-65535 	    3
** 65536-1114111 	4
*/

unsigned short	get_bytes(unsigned int code)
{
	if (code <= 127)
		return (1);
	else if (code <= 2047)
		return (2);
	else if (code <= 65535)
		return (3);
	else
		return (4);
}

/*
** This function get code of char and transform it to unicode
** bytes
** 1 	0xxxxxxx
** 2 	110xxxxx 10xxxxxx
** 3 	1110xxxx 10xxxxxx 10xxxxxx
** 4 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

char			*utf_code(unsigned int code, unsigned short size)
{
	char			*str;

	str = ft_strnew(size);
	if (size == 1)
		str[0] = code;
	else if (size == 2)
	{
		str[0] = 0b11000000 | (code >> 6);
		str[1] = 0b10000000 | (code & 0b00111111);
	}
	else if (size == 3)
	{
		str[0] = 0b11100000 | (code >> 12);
		str[1] = 0b10000000 | ((code >> 6) & 0b00111111);
		str[2] = 0b10000000 | (code & 0b00111111);
	}
	else
	{
		str[0] = 0b11100000 | (code >> 18);
		str[1] = 0b10000000 | ((code >> 12) & 0b00111111);
		str[2] = 0b10000000 | ((code >> 6) & 0b00111111);
		str[3] = 0b10000000 | (code & 0b00111111);
	}
	return (str);
}

char			*extract_symbol(t_format *arg_format, va_list ap)
{
	char			*str;
	char			*ap_str;
	unsigned int	d;

	ap_str = NULL;
	if (arg_format->size == 'l')
	{
		d = va_arg(ap, unsigned int);
		ap_str = utf_code(d, get_bytes(d));
		str = ft_strdup(ap_str);
		ft_strdel(&ap_str);
	}
	else
	{
		str = ft_strnew(1);
		*str = (char)va_arg(ap, int);
	}
	return (str);
}

char			*str_to_utf(unsigned int *str)
{
	char			*res;
	char			*tmp;
	char			*new_str;
	unsigned short	size;

	new_str = ft_strnew(1);
	while (1)
	{
		size = get_bytes(*str);
		tmp = utf_code(*str, size);
		res = ft_strjoin(new_str, tmp);
		ft_strdel(&new_str);
		new_str = res;
		ft_strdel(&tmp);
		if (!*str)
			break ;
		str++;
	}
	return (res);
}
