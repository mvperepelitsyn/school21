/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:50:32 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/04 16:18:26 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_moves(t_stack *stack, int i, int *a_move, int *b_move)
{
	int j;

	get_b_moves(stack, i, b_move);
	j = stack->a_size;
	if (stack->b_stack[i] <= get_max(stack) && stack->b_stack[i] >=
	get_min(stack))
		j = get_j_for_a(stack, i, j);
	else
		j = get_imin(stack);
	if (j == stack->a_size)
		*a_move = 0;
	else if (j > stack->a_size / 2)
		*a_move = stack->a_size - j;
	else if (j <= stack->a_size / 2)
		*a_move = j;
}

int		min_ind(const int *res, int n)
{
	int min;
	int min_i;

	min_i = 0;
	min = 2147483647;
	while (n >= 1)
	{
		if (res[n] < min)
		{
			min = res[n];
			min_i = n;
		}
		n--;
	}
	return (min_i);
}

void	perform_moves(t_stack *stack, int i, int a_move, int b_move)
{
	int j;

	j = stack->a_size;
	if (a_move != 0)
		perform_a_moves(stack, i, j);
	if (b_move != 0)
		perform_b_moves(stack, i);
	apply_pa(stack);
}

void	sort_after_rotates(t_stack *stack)
{
	int i;

	i = min_ind(stack->a_stack, stack->a_size);
	if (i > stack->a_size / 2)
		while (!is_ok_ps(stack))
			apply_ra(stack);
	else
		while (!is_ok_ps(stack))
			apply_rra(stack);
}

void	perform_rotate(t_stack *stack)
{
	int *a_move;
	int *b_move;
	int *res;
	int i;

	res = (int *)malloc(sizeof(int) * (stack->b_size + 1));
	a_move = (int *)malloc(sizeof(int) * (stack->b_size + 1));
	b_move = (int *)malloc(sizeof(int) * (stack->b_size + 1));
	while (stack->b_size != 0)
	{
		i = stack->b_size;
		while (i >= 1)
		{
			get_moves(stack, i, &a_move[i], &b_move[i]);
			res[i] = a_move[i] + b_move[i];
			i--;
		}
		i = min_ind(res, stack->b_size);
		perform_moves(stack, i, a_move[i], b_move[i]);
	}
	sort_after_rotates(stack);
	free(res);
	free(a_move);
	free(b_move);
}
