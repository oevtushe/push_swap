/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:59:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 18:03:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_comb_a(t_list **lst)
{
	int a;
	int b;
	int c;
	int	comb;

	comb = 0;
	a = *(int*)(*lst)->content;
	b = *(int*)(*lst)->next->content;
	c = *(int*)(*lst)->next->next->content;
	if ((a > b && a > c && b > c))
		comb = 1;
	else if (a > b && a > c && b < c)
		comb = 2;
	else if (a < b && c < b && a < c)
		comb = 3;
	else if (a < b && c < b && a > c)
		comb = 4;
	else if (a < c && b < c && a > b)
		comb = 5;
	return (comb);
}

static int get_comb_b(t_list **lst)
{
	int a;
	int b;
	int c;
	int comb;

	comb = 0;
	a = *(int*)(*lst)->content;
	b = *(int*)(*lst)->next->content;
	c = *(int*)(*lst)->next->next->content;
	if (c > a && c > b && b > a)
		comb = 1;
	else if (b > a && b > c && c > a)
		comb = 2;
	else if (a > b && a > c && c > a)
		comb = 3;
	else if (c > a && c > b && a > b)
		comb = 4;
	else if (b > a && b > c && a > c)
		comb = 5;
	return (comb);
}

static void	top_sort(t_list **lst1, t_list **lst2)
{
	int		t1;

	t1 = top_grp_len(*lst1);
	if (t1 == 3)
	{
		if (!get_next_group(*lst1))
		{
			if (*lst2 && !get_next_group(*lst2)  && top_grp_len(*lst2) == 3 && get_comb_a(lst1) == get_comb_b(lst2))
				sort3optim_both(lst1, lst2);
			else
				sort3optimized(lst1, lst2);
		}
		else if (*lst2 && top_grp_len(*lst2) == 3 && get_comb_a(lst1) == get_comb_b(lst2))
		{
			sort3both(lst1, lst2);
		}
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
	t_list	*medians;

	cur_grp = (*lst1)->content_size;
	top_len = top_grp_len(*lst1);
	medians = find_all_nmedians(*lst1, top_len);
	++(*group_cnt);
	while (medians && (int)(*lst1)->content_size == cur_grp)
	{
		split_nmedian_a(lst1, lst2, &medians, group_cnt);
		if (!((t_median*)(medians->content))->push_cnt)
		{
			medians = medians->next;
			++(*group_cnt);
		}
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
