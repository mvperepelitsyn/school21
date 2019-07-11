/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:44:24 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 20:47:41 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "libft.h"
#include "format_checker.h"
#include "apply_utils.h"

/*
** The function return length of non decimal prefix (0x, 0X, 0)
*/

int		len_hex(const char *str, char type, t_format *arg_format)
{
	if (type == 'o' && arg_format->precision >= (int)ft_strlen(str))
		return (0);
	if ((type == 'p' || type == 'x' || type == 'X') && ft_strcmp(str, "0") != 0
		&& ft_strcmp(str, "\0") != 0)
		return (2);
	if (type == 'p' && (*str == '0' || *str == '\0'))
		return (2);
	if (type == 'o' && ft_strcmp(str, "0") != 0)
		return (1);
	return (0);
}

/*
** The function return 1 if sign is necessary
*/

int		get_sign(const char *str, t_format *arg_format)
{
	char	type;

	type = arg_format->type;
	if (type == 'u')
		return (0);
	if ((arg_format->flag[plus] == '1' || arg_format->flag[space] == '1')
		&& str[0] != '-' && arg_format->type != 'c')
		return (1);
	if (str[0] == '-' && (arg_format->precision >= (int)ft_strlen(str)))
		return (1);
	return (0);
}

/*
** The function applies any kinds of prefixes, such as:
** spacial flag for x, X and o types and plus flag for others
*/

void	apply_prefix(t_format *arg_format, char *res, int prefix,
		const char *str)
{
	char	type;
	int		sign;

	sign = get_sign(str, arg_format);
	type = arg_format->type;
	if (*str == '-' && *res != '-')
		ft_chrswap(&res[0], &res[ft_strlen(res) - ft_strlen(str)]);
	res[0] = (sign) ? '+' : res[0];
	res[0] = (sign && arg_format->flag[space] == '1') ? ' ' : res[0];
	res[0] = (prefix) ? '0' : res[0];
	res[1] = (prefix && type == 'X') ? 'X' : res[1];
	res[1] = (prefix && type == 'x') ? 'x' : res[1];
	res[1] = (prefix && type == 'p') ? 'x' : res[1];
}

/*
** This function mix symbols in string for getting right format
*/

void	permutation(char *res, const char *new_str, t_format *arg_format)
{
	if ((arg_format->precision == -1 && arg_format->type != 'f' &&
				arg_format->flag[zero] == '1') && arg_format->type == 'f')
		ft_chrswap(&res[0], &res[ft_strlen(res) - ft_strlen(new_str)]);
	if ((arg_format->flag[spacial] == '1' && (arg_format->flag[zero] == '1'
		|| arg_format->flag[left] == '1') && arg_format->type != 'o'))
		ft_chrswap(&res[1], &res[ft_strlen(res) - ft_strlen(new_str) + 1]);
	if (((*new_str == '-' && res[arg_format->width - ft_strlen(new_str)] != '-')
	|| (*new_str == '+' && res[arg_format->width - ft_strlen(new_str)] != '+'))
	&& arg_format->flag[zero] == '0')
		ft_chrswap(&res[0], &res[ft_strlen(res) - ft_strlen(new_str)]);
	if (((*new_str == '-' && *res != '-') || (*new_str == '+' && *res != '+') ||
	(arg_format->flag[space] == '1' && *new_str == ' ' && *res != ' '))
	&& arg_format->flag[zero] == '1')
		ft_chrswap(&res[0], &res[ft_strlen(res) - ft_strlen(new_str)]);
}

void	cast_big_types(t_format *arg_format)
{
	if (arg_format->type == 'S' || arg_format->type == 'C')
		arg_format->size = 'l';
	if (arg_format->type == 'O' || arg_format->type == 'D' ||
	arg_format->type == 'U')
		arg_format->size = 'I';
	if (arg_format->type != 'X')
		arg_format->type = ft_tolower(arg_format->type);
}
