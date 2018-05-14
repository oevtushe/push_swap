/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optim_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:56:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 11:31:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3optim_b(t_list **lst1, t_list **lst2)
{
	int a;
	int b;
	int c;

	a = *(int*)(*lst2)->content;
	b = *(int*)(*lst2)->next->content;
	c = *(int*)(*lst2)->next->next->content;
	if (c > a && c > b && b > a)
	{
		op_execute_swap_opt(lst1, lst2, 'b');
		op_execute_wrp(lst1, lst2, OP_RRB);
	}
	else if (b > a && b > c && c > a)
		op_execute_wrp(lst1, lst2, OP_RB);
	else if (a > b && a > c && c > a)
	{
		op_execute_wrp(lst1, lst2, OP_RRB);
		op_execute_swap_opt(lst1, lst2, 'b');
	}
	else if (c > a && c > b && a > b)
		op_execute_wrp(lst1, lst2, OP_RRB);
	else if (b > a && b > c && a > c)
		op_execute_swap_opt(lst1, lst2, 'b');
}
