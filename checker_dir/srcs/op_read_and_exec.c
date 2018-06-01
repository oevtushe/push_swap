/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_read_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:14:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 17:53:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			del_op(t_opc **opc)
{
	free((*opc)->op_name);
	free(*opc);
	*opc = NULL;
}

static void			extra_print(t_stacks *stacks, t_pformat *pfmt, char *msg)
{
	t_opc		*tmp;

	tmp = new_opc(OP_NONE, msg);
	init_format(pfmt, tmp->op_name, ES_NONE);
	print_info(stacks, tmp, pfmt);
	PRINT_PROMPT;
	free(tmp);
}

static t_opc		*exec_and_init(t_stacks *stacks, t_list **op_stack, t_excstat *stat, char *line)
{
	t_opc	*opc;
	t_list	*node;

	opc = get_opc(line);
	*stat = op_execute(stacks, opc->abbr);
	node = ft_lstnew(opc, sizeof(t_opc));
	ft_lstadd(op_stack, node);
	return (opc);
}

void				op_read_and_exec(t_stacks *stacks, t_list **op_stack, int fd)
{
	t_excstat	stat;
	char		*line;
	t_pformat	*pfmt;
	t_opc		*opc;

	pfmt = new_pformat(stacks->a);
	extra_print(stacks, pfmt, "init");
	while (get_next_line(fd, &line) > 0)
	{
		if (is_vldop(line))
		{
			opc = exec_and_init(stacks, op_stack, &stat, line);
			init_format(pfmt, opc->op_name, stat);
			print_info(stacks, opc, pfmt);
			free(line);
			del_op(&opc);
		}
		else
			ft_printf("Available commands: pa, pb, sa, sb, ss, \
					ra, rb, rr, rra, rrb, rrr.\nTry again !");
		PRINT_PROMPT;
	}
	print_extra(stacks, pfmt, "finish");
}
