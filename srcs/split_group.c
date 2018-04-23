/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/23 13:28:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_sort(t_stack **stack)
{
	int		t1;

	t1 = top_grp_len((*stack)->lst);
	if (t1 == 3)
		sort3(stack);
	else if (t1 == 2)
		sort2(stack);
}

void	split_group_a(t_stack **stack1, t_stack **stack2)
{
	int		top_len;
	int		cnt_grp;
	int		cur_grp;
	int		gg;

	cur_grp = (*stack1)->lst->content_size;
	cnt_grp = cur_grp;
	while ((top_len = top_grp_len((*stack1)->lst)) > 3 && (int)(*stack1)->lst->content_size == cur_grp)
	{
		++cnt_grp;
		split_nmedian_a(stack1, stack2, top_len, cnt_grp);
	}
	top_sort(stack1);
	if ((top_len = top_grp_len((*stack2)->lst)) > 0)
	{
		cnt_grp = (*stack2)->lst->content_size;
		gg = cur_grp + 1;
		while ((*stack2)->lst && (int)(*stack2)->lst->content_size == cnt_grp)
		{
			(*stack2)->lst->content_size = gg;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PA);
		}
		top_sort(stack1);
	}
}

void	split_group_b(t_stack **stack1, t_stack **stack2)
{
	int		top_len;
	int		cur_grp;
	int		cnt_grp;
	int		gg;

	cur_grp = (*stack2)->lst->content_size;
	cnt_grp = cur_grp;
	while ((top_len = top_grp_len((*stack2)->lst)) > 3 && (int)(*stack2)->lst->content_size == cur_grp)
	{
	//	ft_printf("top_len = %d\n", top_len);
		++cnt_grp;
		split_nmedian_b(stack1, stack2, top_len, cnt_grp);
	}
	//ft_printf("HHEEEEEELLLLLLLOOOOOOO:\n");
	top_sort(stack1);
	if ((top_len = top_grp_len((*stack2)->lst)) > 0)
	{
		cnt_grp = (*stack2)->lst->content_size;
		gg = (*stack1)->lst->content_size + 1;
		while ((*stack2)->lst && (int)(*stack2)->lst->content_size == cnt_grp)
		{
			(*stack2)->lst->content_size = gg;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PA);
		}
		top_sort(stack1);
	}
}
