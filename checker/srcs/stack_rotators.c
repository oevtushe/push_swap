/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:43:12 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 14:43:24 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_rev_rotate(t_list **stack)
{
	t_list *prev;
	t_list *cur;
	t_list *next;

	prev = NULL;
	cur = NULL;
	if (stack && *stack && (*stack)->next)
	{
		next = *stack;
		while (next)
		{
			prev = cur;
			cur = next;
			next = cur->next;
		}
		cur->next = *stack;
		*stack = cur;
		prev->next = NULL;
	}
}

void	execute_rev_rrotate(t_list **a, t_list **b)
{
	execute_rev_rotate(a);
	execute_rev_rotate(b);
}

void	execute_rotate(t_list **stack)
{
	t_list *fst;
	t_list *cur;

	if (stack && *stack && (*stack)->next)
	{
		fst = (*stack)->next;
		cur = fst;
		while (cur->next)
			cur = cur->next;
		cur->next = *stack;
		cur->next->next = NULL;
		*stack = fst;
	}
}

void	execute_rrotate(t_list **a, t_list **b)
{
	execute_rotate(a);
	execute_rotate(b);
}
