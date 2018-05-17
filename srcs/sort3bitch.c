/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3bitch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:18:47 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 17:01:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3
** 2
** 1
*/

static void	sort321(t_list **a, t_list **b)
{
	op_execute_wrp(a, b, OP_SS);
	op_execute_wrp(a, b, OP_RR);
	op_execute_wrp(a, b, OP_SS);
	op_execute_wrp(a, b, OP_RRR);
	op_execute_wrp(a, b, OP_SS);
}

/*
** 3
** 1
** 2
*/

static void	sort312(t_list **a, t_list **b)
{
    op_execute_wrp(a, b, OP_SS);
    op_execute_wrp(a, b, OP_RR);
    op_execute_wrp(a, b, OP_SS);
    op_execute_wrp(a, b, OP_RRR);
}

/*
** 2
** 3
** 1
*/

static void	sort231(t_list **a, t_list **b)
{
    op_execute_wrp(a, b, OP_RR);
    op_execute_wrp(a, b, OP_SS);
    op_execute_wrp(a, b, OP_RRR);
    op_execute_wrp(a, b, OP_SS);
}

/*
** 1
** 3
** 2
*/

static void	sort132(t_list **a, t_list **b)
{
    op_execute_wrp(a, b, OP_RR);
	op_execute_wrp(a, b, OP_SS);
    op_execute_wrp(a, b, OP_RRR);
}

void		sort3bitch(t_list **lst1, t_list **lst2)
{
	int a;
	int b;
	int c;

	a = *(int*)(*lst1)->content;
	b = *(int*)(*lst1)->next->content;
	c = *(int*)(*lst1)->next->next->content;
	if (a > b && a > c && b > c)
		sort321(lst1, lst2);
	else if (a > b && a > c && b < c)
		sort312(lst1, lst2);
	else if (a < b && c < b && a < c)
		sort132(lst1, lst2);
	else if (a < b && c < b && a > c)
		sort231(lst1, lst2);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(lst1, lst2, 'a');
}
