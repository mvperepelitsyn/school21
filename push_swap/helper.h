/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:13:52 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/04 16:15:21 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HELPER_H
# define PUSH_SWAP_HELPER_H

typedef struct	s_stack
{
	int	*a_stack;
	int	*b_stack;
	int	a_size;
	int	b_size;

}				t_stack;

void			parse_args2(t_stack *stack, char **argv, short swtch, int nbr);
void			parse_args1(t_stack *stack, char **argv, int nbr);
void			init_stack(t_stack *stack, int	argc);
void			ft_error(void);
int				give_med(t_stack *stack);
int				give_med_b(t_stack *stack);
short			no_med(t_stack *stack, int med);
short			no_med_b(t_stack *stack, int med);
int				imed(t_stack *stack, int med);
int				imed_b(t_stack *stack, int med);
void			help_parse_args(int argc, char **argv, t_stack *stack);
int				get_j_for_a(t_stack *stack, int i, int j);
void			perform_a_moves(t_stack *stack, int i, int j);
void			perform_b_moves(t_stack *stack, int i);
void			get_b_moves(t_stack *stack, int i, int *b_move);

#endif
