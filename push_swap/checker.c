/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:04:14 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/04 13:22:41 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_ok(t_stack *stack)
{
	int i;

	i = stack->a_size;
	while (i > 1)
	{
		if (stack->a_stack[i] >= stack->a_stack[i - 1])
			return (0);
		i--;
	}
	(stack->b_size == 0) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	exit(0);
}

int		help_cmd(char *cmd)
{
	if (ft_strequ(cmd, ""))
		return (1);
	else
		ft_error();
	return (0);
}

int		get_cmd(t_stack *stack, char *cmd)
{
	if (ft_strequ(cmd, "sa"))
		apply_sa_ch(stack);
	else if (ft_strequ(cmd, "sb"))
		apply_sb_ch(stack);
	else if (ft_strequ(cmd, "ss"))
		apply_ss_ch(stack);
	else if (ft_strequ(cmd, "pa"))
		apply_pa_ch(stack);
	else if (ft_strequ(cmd, "pb"))
		apply_pb_ch(stack);
	else if (ft_strequ(cmd, "ra"))
		apply_ra_ch(stack);
	else if (ft_strequ(cmd, "rb"))
		apply_rb_ch(stack);
	else if (ft_strequ(cmd, "rr"))
		apply_rr_ch(stack);
	else if (ft_strequ(cmd, "rra"))
		apply_rra_ch(stack);
	else if (ft_strequ(cmd, "rrb"))
		apply_rrb_ch(stack);
	else if (ft_strequ(cmd, "rrr"))
		apply_rrr_ch(stack);
	else
		return (help_cmd(cmd));
	return (0);
}

void	do_cmd(t_stack *stack)
{
	char *cmd;

	while (get_next_line(0, &cmd))
	{
		if (!cmd)
			break ;
		if (get_cmd(stack, cmd))
			break ;
		free(cmd);
		cmd = NULL;
	}
	free(cmd);
}

int		main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
		exit(69);
	stack = (t_stack *)malloc(sizeof(t_stack));
	help_parse_args(argc, argv, stack);
	do_cmd(stack);
	if (!(is_ok(stack)))
	{
		ft_putstr("KO\n");
		exit(13);
	}
	return (0);
}
