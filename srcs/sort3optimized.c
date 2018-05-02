/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:25:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 17:36:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3optimized(t_stack **a_stack, t_stack **b_stack)
{
	int a;
	int b;
	int c;

	a = *(int*)(*a_stack)->lst->content;
	b = *(int*)(*a_stack)->lst->next->content;
	c = *(int*)(*a_stack)->lst->next->next->content;
	if (a > b && a > c && b > c)
	{
		op_execute_swap_opt(&(*a_stack)->lst, &(*b_stack)->lst);
		op_execute_wrp(&(*a_stack)->lst, &(*b_stack)->lst, OP_RRA);
	}
	else if (a > b && a > c && b < c)
		op_execute_wrp(&(*a_stack)->lst, &(*b_stack)->lst, OP_RA);
	else if (a < b && c < b && a < c)
	{
		op_execute_swap_opt(&(*a_stack)->lst, &(*b_stack)->lst);
		op_execute_wrp(&(*a_stack)->lst, &(*b_stack)->lst, OP_RRA);
	}
	else if (a < b && c < b && a > c)
		op_execute_wrp(&(*a_stack)->lst, &(*b_stack)->lst, OP_RRA);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(&(*a_stack)->lst, &(*b_stack)->lst);
}
