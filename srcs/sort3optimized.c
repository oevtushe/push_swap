/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:25:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 18:01:15 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
** a > b && a > c && b > c
** a = max b = middle c = min
**
** a > b && a > c && b < c
** a = max b = min c = middle
**
** a < b && c < b && a < c
** a = min b = max c = middle
**
** a < b && c < b && a > c
** a = middle b = max c = min
**
** a < c && b < c && a > b
** a = middle b = min c = max
*/

void	sort3optimized(t_list **lst1, t_list **lst2)
{
	int a;
	int b;
	int c;

	a = *(int*)(*lst1)->content;
	b = *(int*)(*lst1)->next->content;
	c = *(int*)(*lst1)->next->next->content;
	if (a > b && a > c && b > c)
	{
		op_execute_swap_opt(lst1, lst2, 'a');
		op_execute_wrp(lst1, lst2, OP_RRA);
	}
	else if (a > b && a > c && b < c)
		op_execute_wrp(lst1, lst2, OP_RA);
	else if (a < b && c < b && a < c)
	{
		op_execute_wrp(lst1, lst2, OP_RRA);
		op_execute_swap_opt(lst1, lst2, 'a');
	}
	else if (a < b && c < b && a > c)
		op_execute_wrp(lst1, lst2, OP_RRA);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(lst1, lst2, 'a');
}

void	sort3optim_both(t_list **lst1, t_list **lst2)
{
	int a;
	int b;
	int c;

	a = *(int*)(*lst2)->content;
	b = *(int*)(*lst2)->next->content;
	c = *(int*)(*lst2)->next->next->content;
	if (c > a && c > b && b > a)
	{
		op_execute_wrp(lst1, lst2, OP_SS);
		op_execute_wrp(lst1, lst2, OP_RRR);
	}
	else if (b > a && b > c && c > a)
		op_execute_wrp(lst1, lst2, OP_RR);
	else if (a > b && a > c && c > a)
	{
		op_execute_wrp(lst1, lst2, OP_RRR);
		op_execute_wrp(lst1, lst2, OP_SS);
	}
	else if (c > a && c > b && a > b)
		op_execute_wrp(lst1, lst2, OP_RRR);
	else if (b > a && b > c && a > c)
		op_execute_wrp(lst1, lst2, OP_SS);
}
