/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 17:25:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3
** 2
** 1
*/

static void	sort321(t_list **a, t_list **b)
{
	op_execute_swap_opt(a, b);
	op_execute_wrp(a, b, OP_RA);
	op_execute_wrp(a, b, OP_SA);
	op_execute_wrp(a, b, OP_RRA);
	op_execute_wrp(a, b, OP_SA);
}

/*
** 3
** 1
** 2
*/

static void	sort312(t_list **a, t_list **b)
{
	op_execute_swap_opt(a, b);
    op_execute_wrp(a, b, OP_RA);
    op_execute_wrp(a, b, OP_SA);
    op_execute_wrp(a, b, OP_RRA);
}

/*
** 2
** 3
** 1
*/

static void	sort231(t_list **a, t_list **b)
{
    op_execute_wrp(a, b, OP_RA);
	op_execute_swap_opt(a, b);
    op_execute_wrp(a, b, OP_RRA);
    op_execute_wrp(a, b, OP_SA);
}

/*
** 1
** 3
** 2
*/

static void	sort132(t_list **a, t_list **b)
{
    op_execute_wrp(a, b, OP_RA);
	op_execute_swap_opt(a, b);
    op_execute_wrp(a, b, OP_RRA);
}

void		sort3(t_stack **a_stack, t_stack **b_stack)
{
	int a;
	int b;
	int c;

	a = *(int*)(*a_stack)->lst->content;
	b = *(int*)(*a_stack)->lst->next->content;
	c = *(int*)(*a_stack)->lst->next->next->content;
	if (a > b && a > c && b > c)
		sort321(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a > b && a > c && b < c)
		sort312(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a < b && c < b && a < c)
		sort132(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a < b && c < b && a > c)
		sort231(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(&(*a_stack)->lst, &(*b_stack)->lst);
}
