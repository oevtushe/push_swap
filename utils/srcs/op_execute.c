/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:03:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/31 11:03:55 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_excstat	op_execute(t_list **a, t_list **b, t_operation op)
{
	if (op == OP_SA)
		return (execute_swap(*a) ? ES_AM : ES_NONE);
	else if (op == OP_SB)
		return (execute_swap(*b) ? ES_BM : ES_NONE);
	else if (op == OP_SS)
		return (execute_sswap(*a, *b));
	else if (op == OP_PA)
		return (execute_push(a, b) ? ES_AM : ES_NONE);
	else if (op == OP_PB)
		return (execute_push(b, a) ? ES_BM : ES_NONE);
	else if (op == OP_RA)
		return (execute_rotate(a) ? ES_AM : ES_NONE);
	else if (op == OP_RB)
		return (execute_rotate(b) ? ES_BM : ES_NONE);
	else if (op == OP_RR)
		return (execute_rrotate(a, b));
	else if (op == OP_RRA)
		return (execute_rev_rotate(a) ? ES_AM : ES_NONE);
	else if (op == OP_RRB)
		return (execute_rev_rotate(b) ? ES_BM : ES_NONE);
	else if (op == OP_RRR)
		return (execute_rev_rrotate(a, b));
	return (0);
}
