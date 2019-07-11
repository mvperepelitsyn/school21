/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd_ps_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:33:42 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/02 13:33:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	apply_ra(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->a_size + 1;
	tmp = stack->a_stack[stack->a_size];
	while (--i > 1)
	{
		stack->a_stack[i] = stack->a_stack[i - 1];
	}
	stack->a_stack[1] = tmp;
	ft_putstr("ra\n");
}
