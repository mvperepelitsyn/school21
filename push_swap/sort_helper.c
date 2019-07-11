/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:37:47 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/02 13:41:12 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_med(t_stack *stack)
{
	int med;
	int imd;

	med = give_med(stack);
	while (1)
	{
		if (no_med(stack, med) || is_ok_ps(stack))
			break ;
		while (stack->a_stack[stack->a_size] <= med)
			apply_pb(stack);
		if (stack->a_stack[stack->a_size] > med)
		{
			imd = imed(stack, med);
			if (stack->a_stack[stack->a_size - 1] <= med)
				apply_sa(stack);
			else if (imd > stack->a_size / 2 && imd != 0)
				while (stack->a_stack[stack->a_size] > med &&
				!no_med(stack, med))
					apply_ra(stack);
			else if (imd <= stack->a_size / 2 && imd != 0)
				while (stack->a_stack[stack->a_size] > med &&
				!no_med(stack, med))
					apply_rra(stack);
		}
	}
}

void	push_med_a(t_stack *stack)
{
	int med;
	int imed;

	med = give_med_b(stack);
	while (1)
	{
		if (no_med_b(stack, med) || is_ok_ps_b(stack))
			break ;
		while (stack->b_stack[stack->b_size] >= med)
			apply_pa(stack);
		if (stack->b_stack[stack->b_size] < med)
		{
			imed = imed_b(stack, med);
			if (stack->b_stack[stack->b_size - 1] >= med)
				apply_sb(stack);
			else if (imed > stack->b_size / 2 && imed != 0)
				while (stack->b_stack[stack->b_size] < med &&
				!no_med_b(stack, med))
					apply_rb(stack);
			else if (imed <= stack->b_size / 2 && imed != 0)
				while (stack->b_stack[stack->b_size] < med &&
				!no_med_b(stack, med))
					apply_rrb(stack);
		}
	}
}
