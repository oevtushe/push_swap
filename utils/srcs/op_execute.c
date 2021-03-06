/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:03:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 10:29:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_excstat	op_execute(t_stacks *stacks, t_operation op)
{
	if (op == OP_SA)
		return (execute_swap(stacks->a) ? ES_AM : ES_NONE);
	else if (op == OP_SB)
		return (execute_swap(stacks->b) ? ES_BM : ES_NONE);
	else if (op == OP_SS)
		return (execute_sswap(stacks));
	else if (op == OP_PA)
		return (execute_push(&stacks->a, &stacks->b) ? ES_AM : ES_NONE);
	else if (op == OP_PB)
		return (execute_push(&stacks->b, &stacks->a) ? ES_BM : ES_NONE);
	else if (op == OP_RA)
		return (execute_rotate(&stacks->a) ? ES_AM : ES_NONE);
	else if (op == OP_RB)
		return (execute_rotate(&stacks->b) ? ES_BM : ES_NONE);
	else if (op == OP_RR)
		return (execute_rrotate(stacks));
	else if (op == OP_RRA)
		return (execute_rev_rotate(&stacks->a) ? ES_AM : ES_NONE);
	else if (op == OP_RRB)
		return (execute_rev_rotate(&stacks->b) ? ES_BM : ES_NONE);
	else if (op == OP_RRR)
		return (execute_rev_rrotate(stacks));
	return (0);
}
