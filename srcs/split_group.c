/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 14:10:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_sort(t_stack **a, t_stack **b)
{
	int		t1;

	t1 = top_grp_len((*a)->lst);
	if (t1 == 3)
	{
		if (!get_next_group((*a)->lst))
			sort3optimized(a, b);
		else
			sort3(a, b);
	}
	else if (t1 == 2)
		sort2(a, b);
}

static void	sort_group(t_stack **a, t_stack **b, int tbg, int *group_cnt)
{
	split_group_a(a, b, group_cnt);
	while ((int)(*b)->lst->content_size != tbg)
		split_group_b(a, b, group_cnt);
}

void		split_group_a(t_stack **stack1, t_stack **stack2, int *group_cnt)
{
	int		top_len;
	int		cur_grp;

	cur_grp = (*stack1)->lst->content_size;
	while ((top_len = top_grp_len((*stack1)->lst)) > 3 && (int)(*stack1)->lst->content_size == cur_grp)
	{
		++(*group_cnt);
		split_nmedian_a(stack1, stack2, top_len, *group_cnt);
	}
	top_sort(stack1, stack2);
	if ((top_len = top_grp_len((*stack2)->lst)) > 0)
	{
		cur_grp = (*stack2)->lst->content_size;
		++(*group_cnt);
		while ((*stack2)->lst && (int)(*stack2)->lst->content_size == cur_grp)
		{
			(*stack2)->lst->content_size = *group_cnt;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PA);
		}
		top_sort(stack1, stack2);
	}
}

void		split_group_b(t_stack **stack1, t_stack **stack2, int *group_cnt)
{
	int		top_len;
	int		cur_grp;

	cur_grp = (*stack2)->lst->content_size;
	while ((top_len = top_grp_len((*stack2)->lst)) > 3 && (int)(*stack2)->lst->content_size == cur_grp)
	{
		++(*group_cnt);
		split_nmedian_b(stack1, stack2, top_len, *group_cnt);
		if (top_grp_len((*stack1)->lst) > 3)
			sort_group(stack1, stack2, (int)(*stack2)->lst->content_size, group_cnt);
	}
	top_sort(stack1, stack2);
	if ((top_len = top_grp_len((*stack2)->lst)) > 0)
	{
		cur_grp = (*stack2)->lst->content_size;
		++(*group_cnt);
		while ((*stack2)->lst && (int)(*stack2)->lst->content_size == cur_grp)
		{
			(*stack2)->lst->content_size = *group_cnt;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PA);
		}
		top_sort(stack1, stack2);
	}
}
