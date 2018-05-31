/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:57:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/22 14:48:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3
** 2
** 1
*/

static void	sort321(t_stacks *stacks)
{
	op_execute_wrp(stacks, OP_SS);
	op_execute_wrp(stacks, OP_RR);
	op_execute_wrp(stacks, OP_SS);
	op_execute_wrp(stacks, OP_RRR);
	op_execute_wrp(stacks, OP_SS);
}

/*
** 3
** 1
** 2
*/

static void	sort312(t_stacks *stacks)
{
    op_execute_wrp(stacks, OP_SS);
    op_execute_wrp(stacks, OP_RR);
    op_execute_wrp(stacks, OP_SS);
    op_execute_wrp(stacks, OP_RRR);
}

/*
** 2
** 3
** 1
*/

static void	sort231(t_stacks *stacks)
{
    op_execute_wrp(stacks, OP_RR);
    op_execute_wrp(stacks, OP_SS);
    op_execute_wrp(stacks, OP_RRR);
    op_execute_wrp(stacks, OP_SS);
}

/*
** 1
** 3
** 2
*/

static void	sort132(t_stacks *stacks)
{
    op_execute_wrp(stacks, OP_RR);
	op_execute_wrp(stacks, OP_SS);
    op_execute_wrp(stacks, OP_RRR);
}

void		sort3both(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->a->content;
	b = *(int*)stacks->a->next->content;
	c = *(int*)stacks->a->next->next->content;
	if (a > b && a > c && b > c)
		sort321(stacks);
	else if (a > b && a > c && b < c)
		sort312(stacks);
	else if (a < b && c < b && a < c)
		sort132(stacks);
	else if (a < b && c < b && a > c)
		sort231(stacks);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a');
}
