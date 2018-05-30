/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nmedian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/24 17:12:58 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_of_first_to_push(t_list *b)
{
	int		med;
	int		pos;

	pos = 0;
	if (b && ft_lstlen(b) > 3)
	{
		med = find_nmedian(b, top_grp_len(b));
		while (b && *(int*)b->content < med)
		{
			++pos;
			b = b->next;
		}
	}
	return (pos);
}

static void	op_execute_rot_opt(t_stacks *stacks, int *opt)
{
	if (stacks->b && *opt && !get_next_group(stacks->b))
	{
		op_execute_wrp(stacks, OP_RR);
		--(*opt);
	}
	else
		op_execute_wrp(stacks, OP_RA);
}

/*
** Split substack with specified size by median .
**
** @param	size	size of substack.
** @param	ngrp	separated group number.
*/

int		comb_down(t_stacks *stacks, t_median *cur_med, int group_cnt, int ls)
{
	int			opt;
	int			rot_cnt;
	int			is_one_group;

	is_one_group = !get_next_group(stacks->a);
	opt = pos_of_first_to_push(stacks->b);
	rot_cnt = 0;
	while (ls-- > 0)
	{
		if (*(int*)stacks->a->content < cur_med->median)
		{
			stacks->a->content_size = group_cnt;
			op_execute_wrp(stacks, OP_PB);
			--cur_med->push_cnt;
		}
		else
		{
			++rot_cnt;
			op_execute_rot_opt(stacks, &opt);
		}
	}
	return (rot_cnt);
}

void		comb_up(t_stacks *stacks, t_median *cur_med, int group_cnt, int *rot_cnt)
{
	if (get_next_group(stacks->a))
	{
		while ((*rot_cnt)-- && cur_med->push_cnt)
		{
			op_execute_wrp(stacks, OP_RRA);
			if (*(int*)stacks->a->content < cur_med->median)
			{
				--cur_med->push_cnt;
				stacks->a->content_size = group_cnt;
				op_execute_wrp(stacks, OP_PB);
			}
		}
		++(*rot_cnt);
	}
}

void		split_nmedian_a(t_stacks *stacks, t_list *medians, int *group_cnt)
{
	int			ls;
	int			rot_cnt;
	t_median	*cur_med;

	rot_cnt = 0;
	while (medians)
	{
		++(*group_cnt);
		cur_med = (t_median*)medians->content;
		ls = last_less_elem(stacks->a, (int)stacks->a->content_size, cur_med->median);
		if (ls > 0)
			rot_cnt += comb_down(stacks, cur_med, *group_cnt, ls);
		if (cur_med->push_cnt)
			comb_up(stacks, cur_med, *group_cnt, &rot_cnt);
		medians = medians->next;
	}
	if (rot_cnt > 0 && get_next_group(stacks->a))
		while (rot_cnt--)
			op_execute_wrp(stacks, OP_RRA);
}

void		split_nmedian_b(t_stacks *stacks, int median, int group_cnt)
{
	int		rot_cnt;
	int		ls;

	rot_cnt = 0;
	ls = last_bigger_elem(stacks->b, (int)stacks->b->content_size, median);
	while (ls--)
	{
		if (*(int*)stacks->b->content >= median)
		{
			stacks->b->content_size = group_cnt;
			op_execute_wrp(stacks, OP_PA);
		}
		else
		{
			++rot_cnt;
			op_execute_wrp(stacks, OP_RB);
		}
	}
	if (get_next_group(stacks->b))
		while (rot_cnt--)
			op_execute_wrp(stacks, OP_RRB);
}
