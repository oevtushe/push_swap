/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 14:51:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_opc_elem(t_list *elem)
{
	t_opc *opc;

	opc = (t_opc *)elem->content;
	ft_putstr(opc->op_name);
}

static void	print_int_elem(t_list *elem)
{
	int	i;

	i = *(int *)elem->content;
	ft_putnbr(i);
	ft_putchar('\n');
}

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

void		op_executor(t_list **a_stack, t_list *op_stack)
{
	t_opc		*opc;
	t_list		*b_stack;

	b_stack = NULL;
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		op_execute(a_stack, &b_stack, opc->abbr);
		ft_putstr("----- Operation: ");
		print_opc_elem(op_stack);
		ft_putstr(" -----\n");
		ft_putstr("stack a:\n");
		ft_lstiter(*a_stack, print_int_elem);
		ft_putstr("\nstack b:\n");
		ft_lstiter(b_stack, print_int_elem);
		ft_putstr("\n\n");
		op_stack = op_stack->next;
	}
}
