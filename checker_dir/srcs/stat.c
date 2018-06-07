/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 09:16:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 11:54:53 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		count_op(t_operation op, int *stat)
{
	if (op == OP_PA)
		stat[0]++;
	else if (op == OP_RA)
		stat[1]++;
	else if (op == OP_SA)
		stat[2]++;
	else if (op == OP_RRA)
		stat[3]++;
	else if (op == OP_RR)
		stat[4]++;
	else if (op == OP_SS)
		stat[5]++;
	else if (op == OP_RRR)
		stat[6]++;
	else if (op == OP_PB)
		stat[7]++;
	else if (op == OP_RB)
		stat[8]++;
	else if (op == OP_SB)
		stat[9]++;
	else if (op == OP_RRB)
		stat[10]++;
}

static	void	init_stat_arr(t_list *lst, int *stat, int size)
{
	int			i;

	i = 0;
	while (i < size)
		stat[i++] = 0;
	while (lst)
	{
		count_op(((t_opc*)lst->content)->abbr, stat);
		lst = lst->next;
	}
}

static int		cal_col(int *arr, int size)
{
	int	i;
	int	min;
	int	max;
	int	lmin;
	int	lmax;

	i = 0;
	min = arr[0];
	max = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		++i;
	}
	lmin = ft_intln(min);
	lmax = ft_intln(max);
	if (lmin > lmax)
		return (lmin);
	return (lmax);
}

static int		cnt_total(int *stat, int size)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += stat[i];
		++i;
	}
	return (total);
}

void			stat(t_list *lst)
{
	const int	size = 11;
	int			stat[size];
	int			col1;
	int			col2;
	int			col3;

	init_stat_arr(lst, stat, size);
	col1 = cal_col(stat, 4);
	col2 = cal_col(&stat[4], 3);
	col3 = cal_col(&stat[7], 4);
	ft_printf("\033[2J\033[;;H%s%sStatistics%s: (%s%d%s)\n",
			UNDERLINE, GREEN, RESET, BOLD, cnt_total(stat, size), RESET);
	ft_printf("     pa  [%*d]     %*s     pb  [%*d]\n",
			col1, stat[0], col2 + 6, "", col3, stat[7]);
	ft_printf("     ra  [%*d]     rr  [%*d]     rb  [%*d]\n",
			col1, stat[1], col2, stat[4], col3, stat[8]);
	ft_printf("     sa  [%*d]     ss  [%*d]     sb  [%*d]\n",
			col1, stat[2], col2, stat[5], col3, stat[9]);
	ft_printf("     rra [%*d]     rrr [%*d]     rrb [%*d]\n",
			col1, stat[3], col2, stat[6], col3, stat[10]);
}
