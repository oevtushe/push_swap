/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_wrp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:42:12 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 11:08:54 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(t_operation op, int fd)
{
	if (op == OP_SA)
		ft_putendl_fd("sa", fd);
	else if (op == OP_SB)
		ft_putendl_fd("sb", fd);
	else if (op == OP_SS)
		ft_putendl_fd("ss", fd);
	else if (op == OP_PA)
		ft_putendl_fd("pa", fd);
	else if (op == OP_PB)
		ft_putendl_fd("pb", fd);
	else if (op == OP_RA)
		ft_putendl_fd("ra", fd);
	else if (op == OP_RB)
		ft_putendl_fd("rb", fd);
	else if (op == OP_RR)
		ft_putendl_fd("rr", fd);
	else if (op == OP_RRA)
		ft_putendl_fd("rra", fd);
	else if (op == OP_RRB)
		ft_putendl_fd("rrb", fd);
	else if (op == OP_RRR)
		ft_putendl_fd("rrr", fd);
}

void		op_execute_wrp(t_stacks *stacks, t_operation op, int fd)
{
	print_op(op, fd);
	op_execute(stacks, op);
}
