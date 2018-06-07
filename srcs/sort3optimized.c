/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:25:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:12:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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

void	sort3optimized(t_stacks *stacks, int fd)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->a->content;
	b = *(int*)stacks->a->next->content;
	c = *(int*)stacks->a->next->next->content;
	if (a > b && a > c && b > c)
	{
		op_execute_swap_opt(stacks, 'a', fd);
		op_execute_wrp(stacks, OP_RRA, fd);
	}
	else if (a > b && a > c && b < c)
		op_execute_wrp(stacks, OP_RA, fd);
	else if (a < b && c < b && a < c)
	{
		op_execute_wrp(stacks, OP_RRA, fd);
		op_execute_swap_opt(stacks, 'a', fd);
	}
	else if (a < b && c < b && a > c)
		op_execute_wrp(stacks, OP_RRA, fd);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a', fd);
}

void	sort3optim_both(t_stacks *stacks, int fd)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->b->content;
	b = *(int*)stacks->b->next->content;
	c = *(int*)stacks->b->next->next->content;
	if (c > a && c > b && b > a)
	{
		op_execute_wrp(stacks, OP_SS, fd);
		op_execute_wrp(stacks, OP_RRR, fd);
	}
	else if (b > a && b > c && c > a)
		op_execute_wrp(stacks, OP_RR, fd);
	else if (a > b && a > c && c > b)
	{
		op_execute_wrp(stacks, OP_RRR, fd);
		op_execute_wrp(stacks, OP_SS, fd);
	}
	else if (c > a && c > b && a > b)
		op_execute_wrp(stacks, OP_RRR, fd);
	else if (b > a && b > c && a > c)
		op_execute_wrp(stacks, OP_SS, fd);
}
