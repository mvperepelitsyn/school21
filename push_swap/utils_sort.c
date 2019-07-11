/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:22 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/04 16:24:26 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_imin(t_stack *stack)
{
	int i;
	int min;
	int imin;

	i = 0;
	imin = 0;
	min = 2147483647;
	while (++i <= stack->a_size)
	{
		if (stack->a_stack[i] < min)
		{
			min = stack->a_stack[i];
			imin = i;
		}
	}
	return (imin);
}

int		get_j_for_a(t_stack *stack, int i, int j)
{
	while (j > 1)
	{
		if (((stack->b_stack[i] < stack->a_stack[j] && stack->b_stack[i] >
		stack->a_stack[j + 1]) && j != stack->a_size) || (j == stack->a_size &&
		(stack->b_stack[i] < stack->a_stack[j] && stack->b_stack[i] >
		stack->a_stack[1])))
			break ;
		j--;
	}
	return (j);
}

void	perform_a_moves(t_stack *stack, int i, int j)
{
	if (stack->b_stack[i] <= get_max(stack) && stack->b_stack[i] >=
	get_min(stack))
		j = get_j_for_a(stack, i, j);
	else
		j = get_imin(stack);
	if (j == stack->a_size)
		;
	else if (j > stack->a_size / 2)
	{
		while ((stack->a_size - j) > 0)
		{
			apply_ra(stack);
			j++;
		}
	}
	else if (j <= stack->a_size / 2)
	{
		while (j-- > 0)
			apply_rra(stack);
	}
}

void	perform_b_moves(t_stack *stack, int i)
{
	if (i == stack->b_size)
		;
	else if (i > stack->b_size / 2)
	{
		while ((stack->b_size - i) > 0)
		{
			apply_rb(stack);
			i++;
		}
	}
	else if (i <= stack->b_size / 2)
	{
		while (i-- > 0)
			apply_rrb(stack);
	}
}

void	get_b_moves(t_stack *stack, int i, int *b_move)
{
	if (i == stack->b_size)
		*b_move = 0;
	else if (i > stack->b_size / 2)
		*b_move = stack->b_size - i;
	else if (i <= stack->b_size / 2)
		*b_move = i;
}
