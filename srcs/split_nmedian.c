/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nmedian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:43:39 by oevtushe         ###   ########.fr       */
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

/*
** Split substack with specified size by median .
**
** @param	size	size of substack.
** @param	ngrp	separated group number.
*/

static int	comb_down(t_stacks *stacks, t_median *cur_med, int ls, int fd)
{
	int			opt;
	int			rot_cnt;

	opt = pos_of_first_to_push(stacks->b);
	rot_cnt = 0;
	while (ls-- > 0)
	{
		if (*(int*)stacks->a->content < cur_med->median)
		{
			stacks->a->content_size = stacks->grp_cnt;
			op_execute_wrp(stacks, OP_PB, fd);
			--cur_med->push_cnt;
		}
		else
		{
			++rot_cnt;
			op_execute_rot_opt(stacks, &opt, fd);
		}
	}
	return (rot_cnt);
}

static void	comb_up(t_stacks *stacks, t_median *cur_med, int *rot_cnt, int fd)
{
	if (get_next_group(stacks->a))
	{
		while ((*rot_cnt)-- && cur_med->push_cnt)
		{
			op_execute_wrp(stacks, OP_RRA, fd);
			if (*(int*)stacks->a->content < cur_med->median)
			{
				--cur_med->push_cnt;
				stacks->a->content_size = stacks->grp_cnt;
				op_execute_wrp(stacks, OP_PB, fd);
			}
		}
		++(*rot_cnt);
	}
}

void		split_nmedian_a(t_stacks *stacks, t_list *medians, int fd)
{
	int			ls;
	int			rot_cnt;
	t_median	*cur_med;

	rot_cnt = 0;
	while (medians)
	{
		++stacks->grp_cnt;
		cur_med = (t_median*)medians->content;
		ls = last_less_elem(stacks->a,\
				(int)stacks->a->content_size, cur_med->median);
		if (ls > 0)
			rot_cnt += comb_down(stacks, cur_med, ls, fd);
		if (cur_med->push_cnt)
			comb_up(stacks, cur_med, &rot_cnt, fd);
		medians = medians->next;
	}
	if (rot_cnt > 0 && get_next_group(stacks->a))
		while (rot_cnt--)
			op_execute_wrp(stacks, OP_RRA, fd);
}

void		split_nmedian_b(t_stacks *stacks, int median, int fd)
{
	int		rot_cnt;
	int		ls;

	rot_cnt = 0;
	ls = last_bigger_elem(stacks->b, (int)stacks->b->content_size, median);
	while (ls--)
	{
		if (*(int*)stacks->b->content >= median)
		{
			stacks->b->content_size = stacks->grp_cnt;
			op_execute_wrp(stacks, OP_PA, fd);
		}
		else
		{
			++rot_cnt;
			op_execute_wrp(stacks, OP_RB, fd);
		}
	}
	if (get_next_group(stacks->b))
		while (rot_cnt--)
			op_execute_wrp(stacks, OP_RRB, fd);
}
