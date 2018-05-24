/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optim_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:56:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/22 14:46:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3optim_b(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->b->content;
	b = *(int*)stacks->b->next->content;
	c = *(int*)stacks->b->next->next->content;
	if (c > a && c > b && b > a)
	{
		op_execute_swap_opt(stacks, 'b');
		op_execute_wrp(stacks, OP_RRB);
	}
	else if (b > a && b > c && c > a)
		op_execute_wrp(stacks, OP_RB);
	else if (a > b && a > c && c > a)
	{
		op_execute_wrp(stacks, OP_RRB);
		op_execute_swap_opt(stacks, 'b');
	}
	else if (c > a && c > b && a > b)
		op_execute_wrp(stacks, OP_RRB);
	else if (b > a && b > c && a > c)
		op_execute_swap_opt(stacks, 'b');
}
