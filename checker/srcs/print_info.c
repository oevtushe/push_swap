/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:02:27 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/21 12:24:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		print_cstacks(t_list **a, t_list **b, t_excstat stat)
{
	void (*pf)(t_list **, t_list **, char*);

	pf = NULL;
	if (stat == ES_BOTH)
		pf = print_crow;
	else if (stat == ES_AM)
		pf = print_crow_a;
	else if (stat == ES_BM)
		pf = print_crow_b;
	if (pf)
		while (*a || *b)
			pf(a, b, RED);
}

static void		op_print(t_list **a, t_list **b, t_operation op, t_excstat stat)
{
	if (op == OP_SA && stat == ES_AM)
		print_swap(a, b, print_crow_a);
	else if (op == OP_SB && stat == ES_BM)
		print_swap(a, b, print_crow_b);
	else if (op == OP_SS && stat != ES_NONE)
		print_sswap(a, b, stat);
	else if (op == OP_PA && stat == ES_AM)
		print_crow_a(a, b, RED);
	else if (op == OP_PB && stat == ES_BM)
		print_crow_b(a, b, RED);
	else if ((op == OP_RA || op == OP_RRA) && stat == ES_AM)
		print_cstacks(a, b, stat);
	else if ((op == OP_RB || op == OP_RRB) && stat == ES_BM)
		print_cstacks(a, b, stat);
	else if ((op == OP_RR || op == OP_RRR) && stat != ES_NONE)
		print_cstacks(a, b, stat);
}

void			print_info(t_list *a, t_list *b, t_opc *opc, t_excstat stat)
{
	char c;

	ft_printf("\033[2J\033[;;H----- Operation: %s -----\n", opc->op_name);
	op_print(&a, &b, opc->abbr, stat);
	while (a || b)
		print_row(&a, &b);
	ft_printf("%c%5c\n", '_', '_');
	ft_printf("%c%5c\n", 'a', 'b');
	ft_printf("\n%s%s->%s ", BOLD, GREEN, RESET);
	read(1, &c, 1);
}
