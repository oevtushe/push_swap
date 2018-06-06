/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_read_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:14:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 11:38:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				op_read_and_exec(t_stacks *stacks, int fd)
{
	t_excstat	stat;
	char		*line;
	t_pformat	*pfmt;
	t_opc		*opc;
	t_opc		*tmp;

	pfmt = new_pformat(stacks->a);
	tmp = new_opc(OP_NONE, "init");
	init_format(pfmt, tmp->op_name, ES_NONE);
	print_info(stacks, tmp, pfmt);
	PRINT_PROMPT;
	// free tmp
	while (get_next_line(fd, &line) > 0)
	{
		if (is_vldop(line))
		{
			opc = get_opc(line);
			stat = op_execute(stacks, opc->abbr);
			init_format(pfmt, opc->op_name, stat);
			print_info(stacks, opc, pfmt);
			pfmt_prep_to_next(pfmt);
		}
		else
			ft_printf("Try something better.");
		PRINT_PROMPT;
		ft_strdel(&line);
	}
	print_extra(stacks, pfmt, "finish");
	free_pfmt(&pfmt);
}
