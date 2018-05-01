/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:02:27 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/01 14:09:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		op_print(t_list **a, t_list **b, t_operation op, t_pformat *pfmt)
{
	if (pfmt->stat != ES_NONE)
	{
		if (op == OP_SA || op == OP_SB || op == OP_SS)
		{
			print_row(a, b, pfmt);
			print_row(a, b, pfmt);
		}
		else if (op == OP_PA || op == OP_PB)
			print_row(a, b, pfmt);
		else if (op == OP_RA || op == OP_RB || op == OP_RR ||
					op == OP_RRA || op == OP_RRB || op == OP_RRR)
			while (*a || *b)
				print_row(a, b, pfmt);
	}
}

static char		*make_header(t_pformat *pfmt)
{
	char		*tmp;
	int			c3;

	tmp = ft_strdup(" Operation: %s ");
	ft_strcntllr(&tmp, ft_strlen(tmp) + pfmt->bi_ln + 2, '_', -1);
	c3 = ft_strlen(tmp);
	ft_strcntllr(&tmp, ft_strlen(tmp) + pfmt->bi_ln + 2, '_', 1);
	tmp[0] = ' ';
	tmp[pfmt->bi_ln + 1] = ' ';
	tmp[c3] = ' ';
	tmp[ft_strlen(tmp) - 1] = ' ';
	ft_strconnect(&tmp, "\033[2J\033[;;H", -1);
	ft_strconnect(&tmp, "\n", 1);
	return (tmp);
}

void			print_info(t_list *a, t_list *b, t_opc *opc, t_pformat *pfmt)
{
	char		*command;
	char		*header;

	header = make_header(pfmt);
	ft_printf(header, opc->op_name);
	op_print(&a, &b, opc->abbr, pfmt);
	pfmt->stat = ES_NONE;
	while (a || b || !pfmt->ba->is_nm_printed || !pfmt->bb->is_nm_printed)
		print_row(&a, &b, pfmt);
	ft_printf("\n%s%s->%s ", BOLD, GREEN, RESET);
	get_next_line(1, &command);
	free(command);
	free(header);
}
