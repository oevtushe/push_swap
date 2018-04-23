/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nmedian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/23 15:38:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Split substack with specified size by median .
**
** @param	size	size of substack.
** @param	ngrp	separated group number.
*/

void		split_nmedian_a(t_stack **stack1, t_stack **stack2, int grp_size, int ngrp)
{
	int		median;
	int		rot_cnt;
	int		ls;

	rot_cnt = 0;
	median = find_nmedian((*stack1)->lst, grp_size);
	ls = last_less_elem(stack1, (int)(*stack1)->lst->content_size, median);
	while (ls--)
	{
		if (*(int*)(*stack1)->lst->content < median)
		{
			(*stack1)->lst->content_size = ngrp;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PB);
		}
		else
		{
			++rot_cnt;
			op_execute_wrp(&(*stack1)->lst, NULL, OP_RA);
		}
	}
	if (get_next_group((*stack1)->lst))
		while (rot_cnt--)
			op_execute_wrp(&(*stack1)->lst, NULL, OP_RRA);
}

void		split_nmedian_b(t_stack **stack1, t_stack **stack2, int grp_size, int ngrp)
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
			(*stack2)->lst->content_size = ngrp;
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
