/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/30 15:44:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** C
** B
** A
*/

static void	sort_CBA(t_stacks *stacks)
{
	op_execute_swap_opt(stacks, 'a');
	op_execute_wrp(stacks, OP_RA);
	op_execute_wrp(stacks, OP_SA);
	op_execute_wrp(stacks, OP_RRA);
	op_execute_wrp(stacks, OP_SA);
}

/*
** C
** A
** B
*/

static void	sort_CAB(t_stacks *stacks)
{
	op_execute_swap_opt(stacks, 'a');
    op_execute_wrp(stacks, OP_RA);
    op_execute_wrp(stacks, OP_SA);
    op_execute_wrp(stacks, OP_RRA);
}

/*
** B
** C
** A
*/

static void	sort_BCA(t_stacks *stacks)
{
    op_execute_wrp(stacks, OP_RA);
	op_execute_swap_opt(stacks, 'a');
    op_execute_wrp(stacks, OP_RRA);
    op_execute_wrp(stacks, OP_SA);
}

/*
** A
** C
** B
*/

static void	sort_ACB(t_stacks *stacks)
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
		sort_CBA(stacks);
	else if (a > b && a > c && b < c)
		sort_CAB(stacks);
	else if (a < b && c < b && a < c)
		sort_ACB(stacks);
	else if (a < b && c < b && a > c)
		sort_BCA(stacks);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a');
}
