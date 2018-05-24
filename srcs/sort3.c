/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/22 14:49:51 by oevtushe         ###   ########.fr       */
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
	op_execute_swap_opt(stacks, 'a');
	op_execute_wrp(stacks, OP_RA);
	op_execute_wrp(stacks, OP_SA);
	op_execute_wrp(stacks, OP_RRA);
	op_execute_wrp(stacks, OP_SA);
}

/*
** 3
** 1
** 2
*/

static void	sort312(t_stacks *stacks)
{
	op_execute_swap_opt(stacks, 'a');
    op_execute_wrp(stacks, OP_RA);
    op_execute_wrp(stacks, OP_SA);
    op_execute_wrp(stacks, OP_RRA);
}

/*
** 2
** 3
** 1
*/

static void	sort231(t_stacks *stacks)
{
    op_execute_wrp(stacks, OP_RA);
	op_execute_swap_opt(stacks, 'a');
    op_execute_wrp(stacks, OP_RRA);
    op_execute_wrp(stacks, OP_SA);
}

/*
** 1
** 3
** 2
*/

static void	sort132(t_stacks *stacks)
{
    op_execute_wrp(stacks, OP_RA);
	op_execute_swap_opt(stacks, 'a');
    op_execute_wrp(stacks, OP_RRA);
}

void		sort3(t_stacks *stacks)
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
