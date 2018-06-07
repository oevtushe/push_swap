/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eq_combs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:44:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:57:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_comb	get_comb_a(t_list *lst)
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
		comb = CBA;
	else if (a > b && a > c && b < c)
		comb = CAB;
	else if (a < b && c < b && a < c)
		comb = ACB;
	else if (a < b && c < b && a > c)
		comb = BCA;
	else if (a < c && b < c && a > b)
		comb = BAC;
	return (comb);
}

t_comb	get_comb_b(t_list *lst)
{
	int		a;
	int		b;
	int		c;
	t_comb	comb;

	comb = 0;
	a = *(int*)lst->content;
	b = *(int*)lst->next->content;
	c = *(int*)lst->next->next->content;
	if (c > a && c > b && b > a)
		comb = ABC;
	else if (b > a && b > c && c > a)
		comb = ACB;
	else if (a > b && a > c && c > b)
		comb = CAB;
	else if (c > a && c > b && a > b)
		comb = BAC;
	else if (b > a && b > c && a > c)
		comb = BCA;
	return (comb);
}

int		is_eq_combs(t_stacks *stacks)
{
	t_comb ac;
	t_comb bc;

	ac = get_comb_a(stacks->a);
	bc = get_comb_b(stacks->b);
	if (ac + bc == 0)
		return (1);
	return (0);
}
