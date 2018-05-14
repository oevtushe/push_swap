/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_swap_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:48:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 11:25:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_execute_swap_opt(t_list **a, t_list **b, char stack)
{
	if (b && *b && (*b)->next && 
			*(int*)(*b)->content < *(int*)(*b)->next->content)
		op_execute_wrp(a, b, OP_SS);
	else
	{
		if (stack == 'a')
			op_execute_wrp(a, b, OP_SA);
		else
			op_execute_wrp(a, b, OP_SB);
	}
}
