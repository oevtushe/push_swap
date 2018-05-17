/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:25:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/11 11:35:30 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		op_execute_swap_opt(lst1, lst2);
		op_execute_wrp(lst1, lst2, OP_RRA);
	}
	else if (a > b && a > c && b < c)
		op_execute_wrp(lst1, lst2, OP_RA);
	else if (a < b && c < b && a < c)
	{
		op_execute_swap_opt(lst1, lst2);
		op_execute_wrp(lst1, lst2, OP_RRA);
	}
	else if (a < b && c < b && a > c)
		op_execute_wrp(lst1, lst2, OP_RRA);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(lst1, lst2);
}
