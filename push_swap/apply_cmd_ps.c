/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:33:12 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/02 13:33:15 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	apply_sa(t_stack *stack)
{
	int tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_stack[stack->a_size];
	stack->a_stack[stack->a_size] = stack->a_stack[stack->a_size - 1];
	stack->a_stack[stack->a_size - 1] = tmp;
	ft_putstr("sa\n");
}

void	apply_sb(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_stack[stack->b_size];
	stack->b_stack[stack->b_size] = stack->b_stack[stack->b_size - 1];
	stack->b_stack[stack->b_size - 1] = tmp;
	ft_putstr("sb\n");
}

void	apply_ss(t_stack *stack)
{
	apply_sa_ch(stack);
	apply_sb_ch(stack);
	ft_putstr("ss\n");
}

void	apply_pa(t_stack *stack)
{
	if (stack->b_size == 0)
		return ;
	stack->a_size++;
	stack->a_stack[stack->a_size] = stack->b_stack[stack->b_size];
	stack->b_size--;
	ft_putstr("pa\n");
}

void	apply_pb(t_stack *stack)
{
	if (stack->a_size == 0)
		return ;
	stack->b_size++;
	stack->b_stack[stack->b_size] = stack->a_stack[stack->a_size];
	stack->a_size--;
	ft_putstr("pb\n");
}
