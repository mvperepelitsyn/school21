/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd_ch_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:31:47 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/02 13:31:49 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_rb_ch(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->b_size + 1;
	tmp = stack->b_stack[stack->b_size];
	while (--i > 1)
		stack->b_stack[i] = stack->b_stack[i - 1];
	stack->b_stack[1] = tmp;
}

void	apply_rr_ch(t_stack *stack)
{
	apply_ra_ch(stack);
	apply_rb_ch(stack);
}

void	apply_rra_ch(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->a_stack[1];
	while (++i < stack->a_size)
		stack->a_stack[i] = stack->a_stack[i + 1];
	stack->a_stack[stack->a_size] = tmp;
}

void	apply_rrb_ch(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->b_stack[1];
	while (++i < stack->b_size)
		stack->b_stack[i] = stack->b_stack[i + 1];
	stack->b_stack[stack->b_size] = tmp;
}

void	apply_rrr_ch(t_stack *stack)
{
	apply_rra_ch(stack);
	apply_rrb_ch(stack);
}
