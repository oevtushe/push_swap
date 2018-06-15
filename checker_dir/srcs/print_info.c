/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:02:27 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 18:39:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		op_print(t_stacks *stacks, t_operation op, t_pformat *pfmt)
{
	if (pfmt->stat != ES_NONE)
	{
		if (op == OP_SA || op == OP_SB || op == OP_SS)
		{
			print_row(stacks, pfmt);
			print_row(stacks, pfmt);
		}
		else if (op == OP_PA || op == OP_PB)
			print_row(stacks, pfmt);
		else if (op == OP_RA || op == OP_RB || op == OP_RR ||
					op == OP_RRA || op == OP_RRB || op == OP_RRR)
			while (stacks->a || stacks->b)
				print_row(stacks, pfmt);
	}
}

char			*prompt(void)
{
	char	*cmd;

	cmd = NULL;
	PRINT_PROMPT;
	get_next_line(1, &cmd);
	return (cmd);
}

void			print_extra(t_stacks *stacks, t_pformat *pfmt, char *text)
{
	t_opc	*tmp;
	char	*cmd;

	tmp = new_opc(OP_NONE, text);
	init_format(pfmt, tmp->op_name, ES_NONE);
	print_info(stacks, tmp, pfmt);
	cmd = prompt();
	ft_strdel(&cmd);
	pfmt_prep_to_next(pfmt);
	free_opc(&tmp);
}

void			print_info(t_stacks *stacks, t_opc *opc, t_pformat *pfmt)
{
	t_stacks	*cpy;

	cpy = new_stacks(stacks->a, stacks->b);
	ft_printf("\033[2J\033[1;1H%c%*&%c Operation: %s %c%*&%c\n", pfmt->ufmt.tl,
			pfmt->bi_ln, pfmt->ufmt.tm, pfmt->ufmt.tr, opc->op_name,
			pfmt->ufmt.tl, pfmt->bi_ln, pfmt->ufmt.tm, pfmt->ufmt.tr);
	op_print(cpy, opc->abbr, pfmt);
	pfmt->stat = ES_NONE;
	while (cpy->a || cpy->b ||
			!pfmt->ba->is_nm_printed || !pfmt->bb->is_nm_printed)
		print_row(cpy, pfmt);
	free_stacks(&cpy);
}
