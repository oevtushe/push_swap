/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:25:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/30 16:01:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
** a > b && a > c && b > c
** a = max b = middle c = min
**
** a > b && a > c && b < c
** a = max b = min c = middle
**
** a < b && c < b && a < c
** a = min b = max c = middle
**
** a < b && c < b && a > c
** a = middle b = max c = min
**
** a < c && b < c && a > b
** a = middle b = min c = max
*/

void	sort3optimized(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->a->content;
	b = *(int*)stacks->a->next->content;
	c = *(int*)stacks->a->next->next->content;
	if (a > b && a > c && b > c)
	{
		op_execute_swap_opt(stacks, 'a');
		op_execute_wrp(stacks, OP_RRA);
	}
	else if (a > b && a > c && b < c)
		op_execute_wrp(stacks, OP_RA);
	else if (a < b && c < b && a < c)
	{
		op_execute_wrp(stacks, OP_RRA);
		op_execute_swap_opt(stacks, 'a');
	}
	else if (a < b && c < b && a > c)
		op_execute_wrp(stacks, OP_RRA);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a');
}

void	sort3optim_both(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->b->content;
	b = *(int*)stacks->b->next->content;
	c = *(int*)stacks->b->next->next->content;
	if (c > a && c > b && b > a)
	{
		op_execute_wrp(stacks, OP_SS);
		op_execute_wrp(stacks, OP_RRR);
	}
	else if (b > a && b > c && c > a)
		op_execute_wrp(stacks, OP_RR);
	else if (a > b && a > c && c > b)
	{
		op_execute_wrp(stacks, OP_RRR);
		op_execute_wrp(stacks, OP_SS);
	}
	else if (c > a && c > b && a > b)
		op_execute_wrp(stacks, OP_RRR);
	else if (b > a && b > c && a > c)
		op_execute_wrp(stacks, OP_SS);
}
