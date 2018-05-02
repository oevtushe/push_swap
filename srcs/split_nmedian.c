/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nmedian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 14:51:27 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			posofne(t_list *list)
{
	int		med;
	int		pos;

	pos = 0;
	if (list && ft_lstlen(list) > 3)
	{
		pos = 1;
		med = find_nmedian(list, top_grp_len(list));
		while (list && *(int*)list->content < med)
		{
			++pos;
			list = list->next;
		}
	}
	return (pos);
}

/*
** Split substack with specified size by median .
**
** @param	size	size of substack.
** @param	ngrp	separated group number.
*/

void		split_nmedian_a(t_stack **stack1, t_stack **stack2, int grp_size, int group_cnt)
{
	int		median;
	int		rot_cnt;
	int		ls;
	int		opt;

	opt = posofne((*stack2)->lst);
	rot_cnt = 0;
	median = find_nmedian((*stack1)->lst, grp_size);
	ls = last_less_elem(stack1, (int)(*stack1)->lst->content_size, median);
	while (ls--)
	{
		if (*(int*)(*stack1)->lst->content < median)
		{
			(*stack1)->lst->content_size = group_cnt;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PB);
		}
		else
		{
			++rot_cnt;
			if (opt && !get_next_group((*stack2)->lst))
			{
				op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_RR);
				--opt;
			}
			else
				op_execute_wrp(&(*stack1)->lst, NULL, OP_RA);
		}
	}
	if (get_next_group((*stack1)->lst))
		while (rot_cnt--)
			op_execute_wrp(&(*stack1)->lst, NULL, OP_RRA);
}

void		split_nmedian_b(t_stack **stack1, t_stack **stack2, int grp_size, int group_cnt)
{
	int		median;
	int		rot_cnt;
	int		ls;

	rot_cnt = 0;
	median = find_nmedian((*stack2)->lst, grp_size);
	ls = last_bigger_elem(stack2, (int)(*stack2)->lst->content_size, median);
	while (ls--)
	{
		if (*(int*)(*stack2)->lst->content >= median)
		{
			(*stack2)->lst->content_size = group_cnt;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PA);
		}
		else
		{
			++rot_cnt;
			op_execute_wrp(NULL, &(*stack2)->lst, OP_RB);
		}
	}
	if (get_next_group((*stack2)->lst))
		while (rot_cnt--)
			op_execute_wrp(NULL, &(*stack2)->lst, OP_RRB);
}
