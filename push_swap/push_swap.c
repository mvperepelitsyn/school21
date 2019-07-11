/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:37:05 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/03 13:03:24 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ok_ps(t_stack *stack)
{
	int i;

	i = stack->a_size;
	while (i > 1)
	{
		if (stack->a_stack[i] >= stack->a_stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int		is_ok_ps_b(t_stack *stack)
{
	int i;

	i = stack->b_size;
	while (i > 1)
	{
		if (stack->b_stack[i] < stack->b_stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack *stack;

	if (argc <= 1)
		exit(0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	help_parse_args(argc, argv, stack);
	if (is_ok_ps(stack))
		exit(0);
	else
	{
		sort_stack(stack);
		exit(0);
	}
}
