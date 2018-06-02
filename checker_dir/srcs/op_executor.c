/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/02 10:33:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				free_bottom(t_bottom **b)
{
	if ((*b)->separator)
		free((*b)->separator);
	if ((*b)->name)
		free((*b)->name);
	free(*b);
	*b = NULL;
}

void				free_pfmt(t_pformat **pfmt)
{
	free_bottom(&(*pfmt)->ba);
	free_bottom(&(*pfmt)->bb);
	free((*pfmt)->color);
}

void				op_executor(t_stacks *stacks, t_list *op_stack,\
		void print(t_stacks *, t_opc *, t_pformat*))
{
	t_excstat	stat;
	t_opc		*opc;
	t_pformat	*pfmt;
	t_opc		*dft;

	pfmt = new_pformat(stacks->a);
	dft = new_opc(OP_NONE, "finish");
	if (print)
		print_extra(stacks, pfmt, "init");
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		stat = op_execute(stacks, opc->abbr);
		if (print)
		{
			init_format(pfmt, opc->op_name, stat);
			print(stacks, opc, pfmt);
			free(prompt());
			free_bottom(&pfmt->ba);
			free_bottom(&pfmt->bb);
		}
		op_stack = op_stack->next;
	}
	if (print)
		print_extra(stacks, pfmt, "finish");
	free_pfmt(&pfmt);
	free_opc(&dft);
}
