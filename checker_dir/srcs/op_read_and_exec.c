/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_read_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:14:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 15:26:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			print_start(t_stacks *stacks, t_pformat *pfmt)
{
	t_opc *tmp;

	tmp = new_opc(OP_NONE, "init");
	init_format(pfmt, tmp->op_name, ES_NONE);
	print_info(stacks, tmp, pfmt);
	pfmt_prep_to_next(pfmt);
	PRINT_PROMPT;
	free_opc(&tmp);
}

void				op_read_and_exec(t_stacks *stacks, t_list **op_stack, int fd)
{
	t_excstat	stat;
	char		*line;
	t_pformat	*pfmt;
	t_opc		*opc;
	t_list		*tmp;

	pfmt = new_pformat(stacks->a);
	print_start(stacks, pfmt);
	while (get_next_line(fd, &line) > 0)
	{
		if (is_vldop(line))
		{
			opc = get_opc(line);
			tmp = ft_lstnew(opc, sizeof(t_opc));
			ft_lstadd(op_stack, tmp);
			stat = op_execute(stacks, opc->abbr);
			init_format(pfmt, opc->op_name, stat);
			print_info(stacks, opc, pfmt);
			pfmt_prep_to_next(pfmt);
			ft_memdel((void**)&opc);
		}
		else
			ft_printf("Try something better.");
		PRINT_PROMPT;
		ft_strdel(&line);
	}
	print_extra(stacks, pfmt, "finish");
	free_pfmt(&pfmt);
}
