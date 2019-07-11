/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:37:33 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/04 15:35:44 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack1(t_stack *stack)
{
	int max;

	max = get_max(stack);
	if (!is_ok_ps(stack))
	{
		if (max == stack->a_stack[1])
			apply_sa(stack);
		else if (max == stack->a_stack[2])
		{
			apply_rra(stack);
			if (!is_ok_ps(stack))
				apply_sa(stack);
		}
		else if (max == stack->a_stack[3])
		{
			apply_ra(stack);
			if (!(is_ok_ps(stack)))
				apply_sa(stack);
		}
	}
}

void	sort_stack(t_stack *stack)
{
	if (stack->a_size < 4)
		sort_stack1(stack);
	else if (stack->a_size < 110)
	{
		while (stack->a_size > 3)
			apply_pb(stack);
		if (stack->a_size == 3)
			sort_stack1(stack);
		perform_rotate(stack);
	}
	else
	{
		while (!is_ok_ps(stack))
			push_med(stack);
		perform_rotate(stack);
	}
}
