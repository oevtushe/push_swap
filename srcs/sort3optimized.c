/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:25:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 14:08:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3
** 2
** 1
*/

static void	sort321_opt(t_list **a, t_list **b, int which)
{
	t_operation s;
    t_operation rr;

	s = which == 'a' ? OP_SA : OP_SB;
    rr = which == 'a' ? OP_RRA : OP_RRB;
	op_execute_swap_opt(a, b);
	op_execute_wrp(a, b, rr);
}

/*
** 3
** 1
** 2
*/

static void	sort312_opt(t_list **a, t_list **b, int which)
{
    t_operation r;

    r = which == 'a' ? OP_RA : OP_RB;
    op_execute_wrp(a, b, r);
}

/*
** 2
** 3
** 1
*/

static void    sort231_opt(t_list **a, t_list **b, int which)
{
    t_operation rr;

    rr = which == 'a' ? OP_RRA : OP_RRB;
    op_execute_wrp(a, b, rr);
}

/*
** 1
** 3
** 2
*/

static void    sort132_opt(t_list **a, t_list **b, int which)
{
    t_operation s;
    t_operation rr;

    s = which == 'a' ? OP_SA : OP_SB;
    rr = which == 'a' ? OP_RRA : OP_RRB;
    op_execute_wrp(a, b, rr);
	op_execute_swap_opt(a, b);
}

void	sort3optimized(t_stack **a_stack, t_stack **b_stack)
{
	int a;
	int b;
	int c;

	a = *(int*)(*a_stack)->lst->content;
	b = *(int*)(*a_stack)->lst->next->content;
	c = *(int*)(*a_stack)->lst->next->next->content;
	if (a > b && a > c && b > c)
		sort321_opt(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a > b && a > c && b < c)
		sort312_opt(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a < b && c < b && a < c)
		sort132_opt(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a < b && c < b && a > c)
		sort231_opt(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a < c && b < c && a > b)
		sort213(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
}
