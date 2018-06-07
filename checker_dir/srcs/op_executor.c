/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 15:42:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Command line handler.
**
** If 'continue' passed, no print stacks anymore, just print 'OK' 'KO' at the
** end.
*/

static void			handle_cmd(void **print)
{
	char *cmd;

	cmd = prompt();
	if (ft_strequ(cmd, "continue"))
		*print = NULL;
	ft_strdel(&cmd);
}

/*
** Function executes all commands in operation stack
**
** If option -c is has passed, op_executor also prints stacks after
** every operation.
*/

void				op_executor(t_stacks *stacks, t_list *op_stack,\
		void print(t_stacks *, t_opc *, t_pformat*))
{
	t_excstat	stat;
	t_opc		*opc;
	t_pformat	*pfmt;

	pfmt = new_pformat(stacks->a);
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
			handle_cmd((void**)&print);
			pfmt_prep_to_next(pfmt);
		}
		op_stack = op_stack->next;
	}
	if (print)
		print_extra(stacks, pfmt, "finish");
	free_pfmt(&pfmt);
}
