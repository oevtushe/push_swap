/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 11:19:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_sort(t_list **lst1, t_list **lst2)
{
	int		t1;

	t1 = top_grp_len(*lst1);
	if (t1 == 3)
	{
		if (!get_next_group(*lst1))
			sort3optimized(lst1, lst2);
		else
			sort3(lst1, lst2);
		if (ft_lstlen(*lst2) == 3)
			sort3optim_b(lst1, lst2);
	}
	else if (t1 == 2)
		sort2(lst1, lst2);
}

static void	sort_group(t_list **lst1, t_list **lst2, int tbg, int *group_cnt)
{
	split_group_a(lst1, lst2, group_cnt);
	while ((int)(*lst2)->content_size != tbg)
		split_group_b(lst1, lst2, group_cnt);
}

static void	get_head_back(t_list **lst1, t_list **lst2, int *group_cnt)
{
	int		cur_grp;

	cur_grp = (*lst2)->content_size;
	++(*group_cnt);
	while (*lst2 && (int)(*lst2)->content_size == cur_grp)
	{
		(*lst2)->content_size = *group_cnt;
		op_execute_wrp(lst1, lst2, OP_PA);
	}
}

void		split_group_a(t_list **lst1, t_list **lst2, int *group_cnt)
{
	int		top_len;
	int		cur_grp;
	int		median;

	cur_grp = (*lst1)->content_size;
	while ((top_len = top_grp_len(*lst1)) > 3 
			&& (int)(*lst1)->content_size == cur_grp)
	{
		median = find_nmedian(*lst1, top_len);
		++(*group_cnt);
		split_nmedian_a(lst1, lst2, median, *group_cnt);
	}
	top_sort(lst1, lst2);
	if ((top_len = top_grp_len(*lst2)) > 0)
	{
		get_head_back(lst1, lst2, group_cnt);
		top_sort(lst1, lst2);
	}
}

void		split_group_b(t_list **lst1, t_list **lst2, int *group_cnt)
{
	int		top_len;
	int		cur_grp;
	int		median;

	cur_grp = (*lst2)->content_size;
	while ((top_len = top_grp_len(*lst2)) > 3 
			&& (int)(*lst2)->content_size == cur_grp)
	{
		median = find_nmedian(*lst2, top_len);
		split_nmedian_b(lst1, lst2, median, ++(*group_cnt));
		if (top_grp_len(*lst1) > 3)
			sort_group(lst1, lst2,
					(int)(*lst2)->content_size, group_cnt);
	}
	top_sort(lst1, lst2);
	if ((top_len = top_grp_len(*lst2)) > 0)
	{
		get_head_back(lst1, lst2, group_cnt);
		top_sort(lst1, lst2);
	}
}
