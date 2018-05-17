/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:08:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:23:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		execute_rev_rotate(t_list_de **stack)
{
	int		st;
	t_list_de	*prev;
	t_list_de	*cur;
	t_list_de	*next;

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

t_excstat	execute_rev_rrotate(t_list_de **a, t_list_de **b)
{
	t_excstat	stat1;
	t_excstat	stat2;
	t_excstat	stat;

	stat1 = execute_rev_rotate(a) ? ES_AM : ES_NONE;
	stat2 = execute_rev_rotate(b) ? ES_BM : ES_NONE;
	if (stat1 == ES_AM && stat2 == ES_BM)
		stat = ES_BOTH;
	else if (stat1 == ES_AM)
		stat = stat1;
	else
		stat = stat2;
	return (stat);
}

int		execute_rotate(t_list_de **stack)
{
	int		st;
	t_list_de	*fst;
	t_list_de	*cur;

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

t_excstat	execute_rrotate(t_list_de **a, t_list_de **b)
{
	t_excstat	stat1;
	t_excstat	stat2;
	t_excstat	stat;

	stat1 = execute_rotate(a) ? ES_AM : ES_NONE;
	stat2 = execute_rotate(b) ? ES_BM : ES_NONE;
	if (stat1 == ES_AM && stat2 == ES_BM)
		stat = ES_BOTH;
	else if (stat1 == ES_AM)
		stat = stat1;
	else
		stat = stat2;
	return (stat);
}
