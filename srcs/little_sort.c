/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:47:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/14 18:46:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **stack)
{
	int a;
	int b;
	int c;

	a = *(int*)(*stack)->lst->content;
	b = *(int*)(*stack)->lst->next->content;
	c = *(int*)(*stack)->lst->next->next->content;
	if (a > b && a > c && b > c)
		sort321(&(*stack)->lst, NULL, (*stack)->name);
	else if (a > b && a > c && b < c)
		sort312(&(*stack)->lst, NULL, (*stack)->name);
	else if (a < b && c < b && a < c)
		sort132(&(*stack)->lst, NULL, (*stack)->name);
	else if (a < b && c < b && a > c)
		sort231(&(*stack)->lst, NULL, (*stack)->name);
	else if (a < c && b < c && a > b)
		sort213(&(*stack)->lst, NULL, (*stack)->name);
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
		sort321(&(*stack)->lst, NULL, (*stack)->name);
	// 1 3 2
	else if (a < b && a < c && b > c)
		sort312(&(*stack)->lst, NULL, (*stack)->name);
	// 3 1 2
	else if (a > b && c > b && a > c)
		sort132(&(*stack)->lst, NULL, (*stack)->name);
	// 2 1 3
	else if (a > b && c > b && a < c)
		sort231(&(*stack)->lst, NULL, (*stack)->name);
	// 2 1 3
	else if (a < c && b < c && a > b)
		sort213(&(*stack)->lst, NULL, (*stack)->name);
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

void	sort2(t_stack **stack)
{
	int a;
	int b;

	a = *(int*)(*stack)->lst->content;
	b = *(int*)(*stack)->lst->next->content;
	if (a > b)
		op_execute_wrp(&(*stack)->lst, NULL, OP_SA);
}

