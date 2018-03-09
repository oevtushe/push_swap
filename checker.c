/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 14:08:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdio.h>

void	print_int_elem(t_list *elem)
{
	int	i;

	i = *(int *)elem->content;
	ft_putnbr(i);
	ft_putchar('\n');
}

void	print_str_elem(t_list *elem)
{
	ft_putstr((char *)elem->content);
	ft_putchar('\n');
}

void	print_opc_elem(t_list *elem)
{
	t_opc *opc;

	opc = (t_opc *)elem->content;
	ft_putstr(opc->op_name);
}

void	execute_swap(t_list *stack)
{
	void	*tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

void	execute_sswap(t_list *a, t_list *b)
{
	execute_swap(a);
	execute_swap(b);
}

void	execute_push(t_list **fst, t_list **scd)
{
	void	*tmp;

	if (scd && *scd)
	{
		tmp = (*scd)->next;
		ft_lstadd(fst, *scd);
		*scd = tmp;
	}
}

void	execute_rev_rotate(t_list **stack)
{
	t_list *prev;
	t_list *cur;
	t_list *next;

	prev = NULL;
	cur = NULL;
	if (stack && *stack && (*stack)->next)
	{
		next = *stack;
		while (next)
		{
			prev = cur;
			cur = next;
			next = cur->next;
		}
		cur->next = *stack;
		*stack = cur;
		prev->next = NULL;
	}
}

void	execute_rev_rrotate(t_list **a, t_list **b)
{
	execute_rev_rotate(a);
	execute_rev_rotate(b);
}

void	execute_rotate(t_list **stack)
{
	t_list *fst;
	t_list *cur;

	if (stack && *stack && (*stack)->next)
	{
		fst = (*stack)->next;
		cur = fst;
		while (cur->next)
			cur = cur->next;
		cur->next = *stack;
		cur->next->next = NULL;
		*stack = fst;
	}
}

void	execute_rrotate(t_list **a, t_list **b)
{
	execute_rotate(a);
	execute_rotate(b);
}

void	op_execute(t_list **a, t_list **b, t_opc *opc)
{
	if (opc->abbr == OP_SA)
		execute_swap(*a);
	else if (opc->abbr == OP_SB)
		execute_swap(*b);
	else if (opc->abbr == OP_SS)
		execute_sswap(*a, *b);
	else if (opc->abbr == OP_PA)
		execute_push(a, b);
	else if (opc->abbr == OP_PB)
		execute_push(b, a);
	else if (opc->abbr == OP_RA)
		execute_rotate(a);
	else if (opc->abbr == OP_RB)
		execute_rotate(b);
	else if (opc->abbr == OP_RR)
		execute_rrotate(a, b);
	else if (opc->abbr == OP_RRA)
		execute_rev_rotate(a);
	else if (opc->abbr == OP_RRB)
		execute_rev_rotate(b);
	else if (opc->abbr == OP_RRR)
		execute_rev_rrotate(a, b);
}

void	op_executor(t_list **a_stack, t_list *op_stack)
{
	t_opc		*opc;
	t_list		*b_stack;

	b_stack = NULL;
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		op_execute(a_stack, &b_stack, opc);
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

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*op_stack;

	if (argc < 2)
		return (1);
	lst = NULL;
	if (isvldarg(&argv[1], argc - 1))
	{
		lst = read_args_stack(&argv[1], argc - 1);
		ft_lstiter(lst, print_int_elem);
	}
	else
		checker_error("Error\n");
	op_stack = read_operations(1);
	printf("\n\n");
	if (isvldops(op_stack))
	{
		printf("All operations is good !\n\n");
		rebase_op_stack(&op_stack);
		printf("op_stack after rebase\n");
		ft_lstiter(op_stack, print_opc_elem);
		printf("\n");
	}
	else
		checker_error("Error\n");
	op_executor(&lst, op_stack);
	return (0);
}
