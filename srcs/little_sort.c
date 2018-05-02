/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:47:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 14:13:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **a_stack, t_stack **b_stack)
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
		sort213(&(*a_stack)->lst, &(*b_stack)->lst, (*a_stack)->name);
}

void	rsort3(t_stack **stack)
{
	int a;
	int b;
	int c;

	a = *(int*)(*stack)->lst->content;
	b = *(int*)(*stack)->lst->next->content;
	c = *(int*)(*stack)->lst->next->next->content;
	// 1 2 3
	if (a < b && a < c && b < c)
		sort321(NULL, &(*stack)->lst, (*stack)->name);
	// 1 3 2
	else if (a < b && a < c && b > c)
		sort312(NULL, &(*stack)->lst, (*stack)->name);
	// 3 1 2
	else if (a > b && c > b && a > c)
		sort132(NULL, &(*stack)->lst, (*stack)->name);
	// 2 1 3
	else if (a > b && c > b && a < c)
		sort231(NULL, &(*stack)->lst, (*stack)->name);
	// 2 3 1
	else if (a > c && b > c && a < b)
		sort213(NULL, &(*stack)->lst, (*stack)->name);
}

void	rsort2(t_stack **stack)
{
	int a;
	int b;

	a = *(int*)(*stack)->lst->content;
	b = *(int*)(*stack)->lst->next->content;
	if (a < b)
		op_execute_wrp(&(*stack)->lst, NULL, OP_SA);
}

void	sort2(t_stack **a_stack, t_stack **b_stack)
{
	int a;
	int b;

	a = *(int*)(*a_stack)->lst->content;
	b = *(int*)(*a_stack)->lst->next->content;
	if (a > b)
		op_execute_swap_opt(&(*a_stack)->lst, &(*b_stack)->lst);
}
