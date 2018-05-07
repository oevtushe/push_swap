/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 10:14:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				op_executor(t_list **a_stack, t_list **b_stack,
		t_list *op_stack, void print(t_list *, t_list *, t_opc *, t_pformat*))
{
	t_excstat	stat;
	t_opc		*opc;
	t_pformat	*pfmt;
	t_opc		*dft;

	pfmt = new_pformat(*a_stack);
	dft = new_opc(OP_NONE, "finish");
	if (print)
		print_extra(*a_stack, *b_stack, pfmt, "init");
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		stat = op_execute(a_stack, b_stack, opc->abbr);
		if (print)
		{
			init_format(pfmt, opc->op_name, stat);
			print(*a_stack, *b_stack, opc, pfmt);
			free(prompt());
		}
		op_stack = op_stack->next;
	}
	if (print)
		print_extra(*a_stack, *b_stack, pfmt, "finish");
	free(dft);
}
