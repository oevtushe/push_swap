/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 08:13:32 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	op_execute(t_list **a, t_list **b, t_operation op)
{
	if (op == OP_SA)
		execute_swap(*a);
	else if (op == OP_SB)
		execute_swap(*b);
	else if (op == OP_SS)
		execute_sswap(*a, *b);
	else if (op == OP_PA)
		execute_push(a, b);
	else if (op == OP_PB)
		execute_push(b, a);
	else if (op == OP_RA)
		execute_rotate(a);
	else if (op == OP_RB)
		execute_rotate(b);
	else if (op == OP_RR)
		execute_rrotate(a, b);
	else if (op == OP_RRA)
		execute_rev_rotate(a);
	else if (op == OP_RRB)
		execute_rev_rotate(b);
	else if (op == OP_RRR)
		execute_rev_rrotate(a, b);
}

void		print_stacks(t_list *a, t_list *b, t_opc *opc)
{
	ft_printf("----- Operation: %s -----\n", opc->op_name);
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d", *(int*)a->content);
			a = a->next;
		}
		else
			ft_printf(" ");
		if (b)
		{
			ft_printf("%5d\n", *(int*)b->content);
			b = b->next;
		}
		else
			ft_printf("%5s\n", " ");
	}
	ft_printf("%c%5c\n", '_', '_');
	ft_printf("%c%5c\n", 'a', 'b');
}

void		op_executor(t_list **a_stack, t_list *op_stack)
{
	t_opc		*opc;
	t_list		*b_stack;

	b_stack = NULL;
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		op_execute(a_stack, &b_stack, opc->abbr);
		print_stacks(*a_stack, b_stack, opc);
		op_stack = op_stack->next;
	}
}
