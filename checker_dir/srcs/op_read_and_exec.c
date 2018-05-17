/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_read_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:14:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:12:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				op_read_and_exec(t_list_de **a, t_list_de **b, int fd)
{
	t_excstat	stat;
	char		*line;
	t_pformat	*pfmt;
	t_opc		*opc;
	t_opc		*tmp;

	pfmt = new_pformat(*a);
	tmp = new_opc(OP_NONE, "init");
	init_format(pfmt, tmp->op_name, ES_NONE);
	print_info(*a, *b, tmp, pfmt);
	PRINT_PROMPT;
	free(tmp);
	while (get_next_line(fd, &line) > 0)
	{
		if (is_vldop(line))
		{
			opc = get_opc(line);
			stat = op_execute(a, b, opc->abbr);
			init_format(pfmt, opc->op_name, stat);
			print_info(*a, *b, opc, pfmt);
		}
		else
			ft_printf("Try something better.");
		PRINT_PROMPT;
	}
	print_extra(*a, *b, pfmt, "finish");
}
