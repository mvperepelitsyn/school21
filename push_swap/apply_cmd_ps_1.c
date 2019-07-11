/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd_ps_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:33:26 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/02 13:33:28 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	apply_rb(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->b_size + 1;
	tmp = stack->b_stack[stack->b_size];
	while (--i > 1)
		stack->b_stack[i] = stack->b_stack[i - 1];
	stack->b_stack[1] = tmp;
	ft_putstr("rb\n");
}

void	apply_rr(t_stack *stack)
{
	apply_ra_ch(stack);
	apply_rb_ch(stack);
	ft_putstr("rr\n");
}

void	apply_rra(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->a_stack[1];
	while (++i < stack->a_size)
		stack->a_stack[i] = stack->a_stack[i + 1];
	stack->a_stack[stack->a_size] = tmp;
	ft_putstr("rra\n");
}

void	apply_rrb(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->b_stack[1];
	while (++i < stack->b_size)
		stack->b_stack[i] = stack->b_stack[i + 1];
	stack->b_stack[stack->b_size] = tmp;
	ft_putstr("rrb\n");
}

void	apply_rrr(t_stack *stack)
{
	apply_rra_ch(stack);
	apply_rrb_ch(stack);
	ft_putstr("rrr\n");
}
