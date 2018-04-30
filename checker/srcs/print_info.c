/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:02:27 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/30 15:20:31 by oevtushe         ###   ########.fr       */
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

static int		stack_max_int_len(t_list *a)
{
	int		max;

	max = *(int*)a->content;
	while (a)
	{
		if (*(int*)a->content > max)
			max = *(int*)a->content;
		a = a->next;
	}
	return (ft_intln(max));
}


t_pformat		*init_format(t_list *a, char *op_name, t_excstat stat)
{
	t_pformat	*fmt;

	fmt = (t_pformat*)ft_memalloc(sizeof(t_pformat));
	fmt->bi_ln = stack_max_int_len(a);
	fmt->spcs = 14 + (ft_strlen(op_name) == 3 ? 1 : 0);
	fmt->bottom = NULL;
	fmt->color = RED;
	fmt->stat = stat;
	return (fmt);
}

void			print_info(t_list *a, t_list *b, t_opc *opc, t_excstat stat)
{
	char		c;
	t_pformat	*fmt;

	fmt = init_format(a, opc->op_name, stat);
	ft_printf("\033[2J\033[;;H----- Operation: %s -----\n", opc->op_name);
	op_print(&a, &b, opc->abbr, fmt);
	fmt->stat = ES_NONE;
	while (a || b)
		print_row(&a, &b, fmt);
	ft_printf("%c%5c\n", '_', '_');
	ft_printf("%c%5c\n", 'a', 'b');
	ft_printf("\n%s%s->%s ", BOLD, GREEN, RESET);
	read(1, &c, 1);
}
