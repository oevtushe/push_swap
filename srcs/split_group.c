/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 17:07:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		db_stacks(t_stacks *stacks)
{
	t_list	*a;
	t_list	*b;

	a = stacks->a;
	b = stacks->b;
	ft_printf("Stacks:\n");
	while (a || b)
	{
		if (a && b)
			ft_printf("%d[%d]%*s%d[%d]\n", *(int*)a->content,
					(int)a->content_size, 6, "",
					*(int*)b->content, (int)b->content_size);
		else if (a)
			ft_printf("%d[%d]\n", *(int*)a->content, (int)a->content_size);
		else if (b)
			ft_printf("%d[%d]\n", *(int*)b->content, (int)b->content_size);
		a = a->next;
		b = b->next;
	}
}

static void	top_sort(t_stacks *stacks, int fd)
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
	else if (t1 == 2)
	{
		sort2(stacks, fd);
		if (ft_lstlen(stacks->b) == 3)
			sort3optim_b(stacks, fd);
	}
}

static void	get_head_back(t_stacks *stacks, int *group_cnt, int fd)
{
	int		cur_grp;

	cur_grp = stacks->b->content_size;
	++(*group_cnt);
	while (stacks->b && (int)stacks->b->content_size == cur_grp)
	{
		stacks->b->content_size = *group_cnt;
		op_execute_wrp(stacks, OP_PA, fd);
	}
}

void		split_group_a(t_stacks *stacks, int *group_cnt, int fd)
{
	int		top_len;
	int		cur_grp;
	t_list	*medians;

	cur_grp = stacks->a->content_size;
	top_len = top_grp_len(stacks->a);
	medians = find_all_nmedians(stacks->a, top_len);
	split_nmedian_a(stacks, medians, group_cnt, fd);
	top_sort(stacks, fd);
	if ((top_len = top_grp_len(stacks->b)) > 0)
	{
		get_head_back(stacks, group_cnt, fd);
		top_sort(stacks, fd);
	}
}

void		split_group_b(t_stacks *stacks, int *group_cnt, int fd)
{
	int		top_len;
	int		cur_grp;
	int		median;

	cur_grp = stacks->b->content_size;
	while ((top_len = top_grp_len(stacks->b)) > 3 
			&& (int)stacks->b->content_size == cur_grp)
	{
		median = find_nmedian(stacks->b, top_len);
		split_nmedian_b(stacks, median, ++(*group_cnt), fd);
		if (top_grp_len(stacks->a) > 3)
		{
			split_group_a(stacks, group_cnt, fd);
			cur_grp = stacks->b->content_size;
		}
	}
	top_sort(stacks, fd);
	if ((top_len = top_grp_len(stacks->b)) > 0)
	{
		get_head_back(stacks, group_cnt, fd);
		top_sort(stacks, fd);
	}
}
