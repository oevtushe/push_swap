/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_wrp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:42:12 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 11:07:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(t_operation op, int fd)
{
	if (op == OP_SA)
		ft_putstr_fd("sa\n", fd);
	else if (op == OP_SB)
		ft_putstr_fd("sb\n", fd);
	else if (op == OP_SS)
		ft_putstr_fd("ss\n", fd);
	else if (op == OP_PA)
		ft_putstr_fd("pa\n", fd);
	else if (op == OP_PB)
		ft_putstr_fd("pb\n", fd);
	else if (op == OP_RA)
		ft_putstr_fd("ra\n", fd);
	else if (op == OP_RB)
		ft_putstr_fd("rb\n", fd);
	else if (op == OP_RR)
		ft_putstr_fd("rr\n", fd);
	else if (op == OP_RRA)
		ft_putstr_fd("rra\n", fd);
	else if (op == OP_RRB)
		ft_putstr_fd("rrb\n", fd);
	else if (op == OP_RRR)
		ft_putstr_fd("rrr\n", fd);
}

void		op_execute_wrp(t_stacks *stacks, t_operation op, int fd)
{
	print_op(op, fd);
	op_execute(stacks, op);
}
