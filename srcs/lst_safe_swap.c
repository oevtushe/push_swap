/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_safe_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:10:52 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/04 13:10:54 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void op_execute_pr(t_stack **stack, t_opc op)
{
	ft_printf("%s\n", op.op_name);
	if ((*stack)->name == 'a')
		op_execute(&(*stack)->lst, NULL, op.abbr);
	else
		op_execute(NULL, &(*stack)->lst, op.abbr);
}

static void init_op(t_opc *r, t_opc *rr, t_opc *s, char name)
{
	if (name == 'a')
	{
		r->op_name = "ra";
		r->abbr = OP_RA;
		rr->op_name = "rra";
		rr->abbr = OP_RRA;
		s->op_name = "sa";
		s->abbr = OP_SA;
	}
	else
	{
		r->op_name = "rb";
		r->abbr = OP_RB;
		rr->op_name = "rrb";
		rr->abbr = OP_RRB;
		s->op_name = "sb";
		s->abbr = OP_SB;
	}
}

void	lst_safe_swap(t_stack **stack, int i, int j)
{
	int		idx;
	t_opc	r;
	t_opc	rr;
	t_opc	s;

	if (i != j)
	{
		idx = -1;
		init_op(&r, &rr, &s, (*stack)->name);
		while (++idx < i)
			op_execute_pr(stack, r);
		while (++idx < j)
		{
			op_execute_pr(stack, s);
			op_execute_pr(stack, r);
		}
		op_execute_pr(stack, s);
		while (--idx > i)
		{
			op_execute_pr(stack, rr);
			op_execute_pr(stack, s);
		}
		while (--i >= 0)
			op_execute_pr(stack, rr);
	}
}
