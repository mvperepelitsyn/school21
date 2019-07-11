/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:37:15 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/07/04 15:12:16 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "helper.h"

void	apply_sa(t_stack *stack);
void	apply_sb(t_stack *stack);
void	apply_ss(t_stack *stack);
void	apply_pa(t_stack *stack);
void	apply_pb(t_stack *stack);
void	apply_ra(t_stack *stack);
void	apply_rb(t_stack *stack);
void	apply_rr(t_stack *stack);
void	apply_rra(t_stack *stack);
void	apply_rrb(t_stack *stack);
void	apply_rrr(t_stack *stack);
void	sort_stack(t_stack *stack);
int		is_ok_ps(t_stack *stack);
int		is_ok_ps_b(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max_b(t_stack *stack);
int		get_imax_b(t_stack *stack);
int		get_min_b(t_stack *stack);
void	push_med(t_stack *stack);
void	push_med_a(t_stack *stack);
void	sort_stack1(t_stack *stack);
void	new_sort(t_stack *stack);
void	perform_rotate(t_stack *stack);
int		get_imin(t_stack *stack);

#endif
