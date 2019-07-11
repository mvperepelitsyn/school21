/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:31:29 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/02 13:31:34 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_sa_ch(t_stack *stack)
{
	int tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_stack[stack->a_size];
	stack->a_stack[stack->a_size] = stack->a_stack[stack->a_size - 1];
	stack->a_stack[stack->a_size - 1] = tmp;
}

void	apply_sb_ch(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_stack[stack->b_size];
	stack->b_stack[stack->b_size] = stack->b_stack[stack->b_size - 1];
	stack->b_stack[stack->b_size - 1] = tmp;
}

void	apply_ss_ch(t_stack *stack)
{
	apply_sa_ch(stack);
	apply_sb_ch(stack);
}

void	apply_pa_ch(t_stack *stack)
{
	if (stack->b_size == 0)
		return ;
	stack->a_size++;
	stack->a_stack[stack->a_size] = stack->b_stack[stack->b_size];
	stack->b_size--;
}

void	apply_pb_ch(t_stack *stack)
{
	if (stack->a_size == 0)
		return ;
	stack->b_size++;
	stack->b_stack[stack->b_size] = stack->a_stack[stack->a_size];
	stack->a_size--;
}
