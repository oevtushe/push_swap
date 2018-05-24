/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eq_combs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:44:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/22 14:44:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_comb_a(t_list *lst)
{
	int a;
	int b;
	int c;
	int	comb;

	comb = 0;
	a = *(int*)lst->content;
	b = *(int*)lst->next->content;
	c = *(int*)lst->next->next->content;
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

static int get_comb_b(t_list *lst)
{
	int a;
	int b;
	int c;
	int comb;

	comb = 0;
	a = *(int*)lst->content;
	b = *(int*)lst->next->content;
	c = *(int*)lst->next->next->content;
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

int	is_eq_combs(t_stacks *stacks)
{
	return (top_grp_len(stacks->b) == 3 && get_comb_a(stacks->a) == get_comb_b(stacks->b));
}
