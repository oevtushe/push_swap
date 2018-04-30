/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/30 16:50:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			init_format(t_pformat *pfmt, char *op_name, t_excstat stat)
{
	pfmt->spcs = 15 + (ft_strlen(op_name) == 3 ? 1 : 0);
	pfmt->bottom = NULL;
	pfmt->stat = stat;
}

static int		stack_max_int_len(t_list *a)
{
	int		max;

	max = *(int*)a->content;
	while (a)
	{
		if (*(int*)a->content > max)
			max = *(int*)a->content;
		a = a->next;
	}
	return (ft_intln(max));
}

void				op_executor(t_list **a_stack, t_list **b_stack,
		t_list *op_stack, void print(t_list *, t_list *, t_opc *, t_pformat*))
{
	t_excstat	stat;
	t_opc		*opc;
	t_pformat	*pfmt;

	pfmt = (t_pformat*)ft_memalloc(sizeof(t_pformat));
	pfmt->color = RED;
	pfmt->bi_ln = stack_max_int_len(*a_stack);
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		stat = op_execute(a_stack, b_stack, opc->abbr);
		init_format(pfmt, opc->op_name, stat);
		if (print)
			print(*a_stack, *b_stack, opc, pfmt);
		op_stack = op_stack->next;
	}
}
