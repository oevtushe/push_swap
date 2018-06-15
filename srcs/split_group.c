/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:35:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top3sort(t_stacks *stacks, int fd)
{
	size_t b_len;

	b_len = ft_lstlen(stacks->b);
	if (!get_next_group(stacks->a))
	{
		if (b_len == 3 && is_eq_combs(stacks))
			sort3optim_both(stacks, fd);
		else
			sort3optimized(stacks, fd);
	}
	else if (top_grp_len(stacks->b) == 3)
		sort3_new(stacks, fd);
	else if (b_len == 3)
		sort3optim_b(stacks, fd);
	else
		sort3(stacks, fd);
}

static void	top_sort(t_stacks *stacks, int fd)
{
	int		t1;
	size_t	b_len;

	t1 = top_grp_len(stacks->a);
	b_len = ft_lstlen(stacks->b);
	if (t1 == 3)
		top3sort(stacks, fd);
	else if (t1 == 2)
	{
		sort2(stacks, fd);
		if (b_len == 3)
			sort3optim_b(stacks, fd);
	}
}

static void	get_head_back(t_stacks *stacks, int fd)
{
	int		cur_grp;

	cur_grp = stacks->b->content_size;
	++stacks->grp_cnt;
	while (stacks->b && (int)stacks->b->content_size == cur_grp)
	{
		stacks->b->content_size = stacks->grp_cnt;
		op_execute_wrp(stacks, OP_PA, fd);
	}
}

void		split_group_a(t_stacks *stacks, int fd)
{
	int		top_len;
	t_list	*medians;

	top_len = top_grp_len(stacks->a);
	medians = find_all_nmedians(stacks->a, top_len);
	split_nmedian_a(stacks, medians, fd);
	top_sort(stacks, fd);
	if ((top_len = top_grp_len(stacks->b)) > 0)
	{
		get_head_back(stacks, fd);
		top_sort(stacks, fd);
	}
	ft_lstdel(&medians, del_simple);
}

void		split_group_b(t_stacks *stacks, int fd)
{
	int		top_len;
	int		cur_grp;
	int		median;

	cur_grp = stacks->b->content_size;
	while ((top_len = top_grp_len(stacks->b)) > 3
			&& (int)stacks->b->content_size == cur_grp)
	{
		median = find_nmedian(stacks->b, top_len);
		++stacks->grp_cnt;
		split_nmedian_b(stacks, median, fd);
		if (top_grp_len(stacks->a) > 3)
		{
			split_group_a(stacks, fd);
			cur_grp = stacks->b->content_size;
		}
	}
	top_sort(stacks, fd);
	if ((top_len = top_grp_len(stacks->b)) > 0)
	{
		get_head_back(stacks, fd);
		top_sort(stacks, fd);
	}
}
