/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_read_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:14:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 14:54:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			extra_print(t_list_de *a, t_list_de *b, t_pformat *pfmt, char *msg)
{
	t_opc		*tmp;

	tmp = new_opc(OP_NONE, msg);
	init_format(pfmt, tmp->op_name, ES_NONE);
	print_info(a, b, tmp, pfmt);
	PRINT_PROMPT;
	free(tmp);
}

void				op_read_and_exec(t_list_de **a, t_list_de **b, t_list_de **op_stack, int fd)
{
	t_excstat	stat;
	char		*line;
	t_pformat	*pfmt;
	t_opc		*opc;
	t_list_de	*node;

	pfmt = new_pformat(*a);
	extra_print(*a, *b, pfmt, "init");
	while (get_next_line(fd, &line) > 0)
	{
		if (is_vldop(line))
		{
			opc = get_opc(line);
			stat = op_execute(a, b, opc->abbr);
			node = ft_lstnew_de(line, ft_strlen(line) + 1);
			ft_lstadd_de(op_stack, node);
			init_format(pfmt, opc->op_name, stat);
			print_info(*a, *b, opc, pfmt);
			free(line);
		}
		else
			ft_printf("Try something better.");
		PRINT_PROMPT;
	}
	extra_print(*a, *b, pfmt, "finish");
}
