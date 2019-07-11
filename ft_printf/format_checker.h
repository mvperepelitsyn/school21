/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 18:59:27 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/02 19:01:28 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_CHECKER_H
# define FORMAT_CHECKER_H

int	is_flag(char c);
int	is_size(char c);
int	is_type(char c);
int	is_valid(char c);
int	accumulate_digit(int *res, char c);

#endif
