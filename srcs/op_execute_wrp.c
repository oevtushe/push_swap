/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_wrp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:42:12 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 16:58:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(t_operation op)
{
	if (op == OP_SA)
		ft_putstr("sa\n");
	else if (op == OP_SB)
		ft_putstr("sb\n");
	else if (op == OP_SS)
		ft_putstr("ss\n");
	else if (op == OP_PA)
		ft_putstr("pa\n");
	else if (op == OP_PB)
		ft_putstr("pb\n");
	else if (op == OP_RA)
		ft_putstr("ra\n");
	else if (op == OP_RB)
		ft_putstr("rb\n");
	else if (op == OP_RR)
		ft_putstr("rr\n");
	else if (op == OP_RRA)
		ft_putstr("rra\n");
	else if (op == OP_RRB)
		ft_putstr("rrb\n");
	else if (op == OP_RRR)
		ft_putstr("rrr\n");
}

void		op_execute_wrp(t_stacks *stacks, t_operation op)
{
	print_op(op);
	op_execute(stacks, op);
}
