/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nmedian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/05 17:05:26 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	posofne(t_list *list)
{
	int		med;
	int		pos;

	pos = 0;
	if (list && ft_lstlen(list) > 3)
	{
		med = find_nmedian(list, top_grp_len(list));
		while (list && *(int*)list->content < med)
		{
			++pos;
			list = list->next;
		}
	}
	return (pos);
}

static void	op_execute_rot_opt(t_list **lst1, t_list **lst2, int *opt)
{
	if (*lst2 && *opt && !get_next_group(*lst2))
	{
		op_execute_wrp(lst1, lst2, OP_RR);
		--(*opt);
	}
	else
		op_execute_wrp(lst1, NULL, OP_RA);
}

/*
** Split substack with specified size by median .
**
** @param	size	size of substack.
** @param	ngrp	separated group number.
*/

void		split_nmedian_a(t_list **lst1, t_list **lst2, int grp_size, int group_cnt)
{
	int		median;
	int		rot_cnt;
	int		ls;
	int		opt;

	opt = posofne(*lst2);
	rot_cnt = 0;
	median = find_nmedian(*lst1, grp_size);
	ls = last_less_elem(*lst1, (int)(*lst1)->content_size, median);
	while (ls--)
	{
		if (*(int*)(*lst1)->content < median)
		{
			(*lst1)->content_size = group_cnt;
			op_execute_wrp(lst1, lst2, OP_PB);
		}
		else
		{
			++rot_cnt;
			op_execute_rot_opt(lst1, lst2, &opt);
		}
	}
	if (get_next_group(*lst1))
		while (rot_cnt--)
			op_execute_wrp(lst1, NULL, OP_RRA);
}

void		split_nmedian_b(t_list **lst1, t_list **lst2, int grp_size, int group_cnt)
{
	int		median;
	int		rot_cnt;
	int		ls;

	rot_cnt = 0;
	median = find_nmedian(*lst2, grp_size);
	ls = last_bigger_elem(*lst2, (int)(*lst2)->content_size, median);
	while (ls--)
	{
		if (*(int*)(*lst2)->content >= median)
		{
			(*lst2)->content_size = group_cnt;
			op_execute_wrp(lst1, lst2, OP_PA);
		}
		else
		{
			++rot_cnt;
			op_execute_wrp(NULL, lst2, OP_RB);
		}
	}
	if (get_next_group(*lst2))
		while (rot_cnt--)
			op_execute_wrp(NULL, lst2, OP_RRB);
}
