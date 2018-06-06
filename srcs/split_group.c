/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 16:00:15 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_sort(t_stacks *stacks)
{
	int		t1;
	size_t	b_len;

	t1 = top_grp_len(stacks->a);
	b_len = ft_lstlen(stacks->b);
	if (t1 == 3)
	{
		if (!get_next_group(stacks->a))
		{
			if (b_len == 3 && is_eq_combs(stacks))
				sort3optim_both(stacks);
			else
				sort3optimized(stacks);
		}
		else if (top_grp_len(stacks->b) == 3)
			sort3_new(stacks);
		else if (b_len == 3)
			sort3optim_b(stacks);
		else
			sort3(stacks);
	}
	else if (t1 == 2)
	{
		sort2(stacks);
		if (ft_lstlen(stacks->b) == 3)
			sort3optim_b(stacks);
	}
}

static void	get_head_back(t_stacks *stacks, int *group_cnt)
{
	int		cur_grp;

	cur_grp = stacks->b->content_size;
	++(*group_cnt);
	while (stacks->b && (int)stacks->b->content_size == cur_grp)
	{
		stacks->b->content_size = *group_cnt;
		op_execute_wrp(stacks, OP_PA);
	}
}

void		split_group_a(t_stacks *stacks, int *group_cnt)
{
	int		top_len;
	int		cur_grp;
	t_list	*medians;

	cur_grp = stacks->a->content_size;
	top_len = top_grp_len(stacks->a);
	medians = find_all_nmedians(stacks->a, top_len);
	split_nmedian_a(stacks, medians, group_cnt);
	top_sort(stacks);
	if ((top_len = top_grp_len(stacks->b)) > 0)
	{
		get_head_back(stacks, group_cnt);
		top_sort(stacks);
	}
	ft_lstdel(&medians, del_simple);
}

void		split_group_b(t_stacks *stacks, int *group_cnt)
{
	int		top_len;
	int		cur_grp;
	int		median;

	cur_grp = stacks->b->content_size;
	while ((top_len = top_grp_len(stacks->b)) > 3 
			&& (int)stacks->b->content_size == cur_grp)
	{
		median = find_nmedian(stacks->b, top_len);
		split_nmedian_b(stacks, median, ++(*group_cnt));
		if (top_grp_len(stacks->a) > 3)
		{
			split_group_a(stacks, group_cnt);
			cur_grp = stacks->b->content_size;
		}
	}
	top_sort(stacks);
	if ((top_len = top_grp_len(stacks->b)) > 0)
	{
		get_head_back(stacks, group_cnt);
		top_sort(stacks);
	}
}
