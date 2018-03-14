/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:52:54 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 13:07:54 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		print_cstacks(t_list **a, t_list **b, void (*pf)(t_list **a, t_list **b, char *color))
{
	while (*a || *b)
		pf(a, b, RED);
}

void		op_print(t_list **a, t_list **b, t_operation op)
{
	if (op == OP_SA)
		print_swap(a, b, print_crow_a);
	else if (op == OP_SB)
		print_swap(a, b, print_crow_b);
	else if (op == OP_SS)
		print_sswap(a, b);
	else if (op == OP_PA)
		print_crow_a(a, b, RED);
	else if (op == OP_PB)
		print_crow_b(a, b, RED);
	else if (op == OP_RA || op == OP_RRA)
		print_cstacks(a, b, print_crow_a);
	else if (op == OP_RB || op == OP_RRB)
		print_cstacks(a, b, print_crow_b);
	else if (op == OP_RR || op == OP_RRR)
		print_cstacks(a, b, print_crow);
}
