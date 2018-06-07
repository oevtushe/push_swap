/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:08:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:08:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			execute_rev_rotate(t_list **stack)
{
	int		st;
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = NULL;
	if (stack && *stack && (*stack)->next)
	{
		st = 1;
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
	else
		st = 0;
	return (st);
}

t_excstat	execute_rev_rrotate(t_stacks *stacks)
{
	t_excstat	stat1;
	t_excstat	stat2;
	t_excstat	stat;

	stat1 = execute_rev_rotate(&stacks->a) ? ES_AM : ES_NONE;
	stat2 = execute_rev_rotate(&stacks->b) ? ES_BM : ES_NONE;
	if (stat1 == ES_AM && stat2 == ES_BM)
		stat = ES_BOTH;
	else if (stat1 == ES_AM)
		stat = stat1;
	else
		stat = stat2;
	return (stat);
}

int			execute_rotate(t_list **stack)
{
	int		st;
	t_list	*fst;
	t_list	*cur;

	if (stack && *stack && (*stack)->next)
	{
		st = 1;
		fst = (*stack)->next;
		cur = fst;
		while (cur->next)
			cur = cur->next;
		cur->next = *stack;
		cur->next->next = NULL;
		*stack = fst;
	}
	else
		st = 0;
	return (st);
}

t_excstat	execute_rrotate(t_stacks *stacks)
{
	t_excstat	stat1;
	t_excstat	stat2;
	t_excstat	stat;

	stat1 = execute_rotate(&stacks->a) ? ES_AM : ES_NONE;
	stat2 = execute_rotate(&stacks->b) ? ES_BM : ES_NONE;
	if (stat1 == ES_AM && stat2 == ES_BM)
		stat = ES_BOTH;
	else if (stat1 == ES_AM)
		stat = stat1;
	else
		stat = stat2;
	return (stat);
}
