/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_swap_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:48:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 14:35:43 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_execute_swap_opt(t_list **a, t_list **b, char stack)
{
	int done;

	done = 0;
	if (b && *b)
	{
		if (top_grp_len(*b) == 2 && *(int*)(*b)->content < *(int*)(*b)->next->content)
		{
			op_execute_wrp(a, b, OP_SS);
			done = 1;
		}
		else if (top_grp_len(*b) == 3 && *(int*)(*b)->content < *(int*)(*b)->next->content && 
				*(int*)(*b)->next->content > *(int*)(*b)->next->next->content &&
					*(int*)(*b)->content > *(int*)(*b)->next->next->content)
		{
			op_execute_wrp(a, b, OP_SS);
			done = 1;
		}
	}
	if (!done)
	{
		if (stack == 'a')
			op_execute_wrp(a, b, OP_SA);
		else
			op_execute_wrp(a, b, OP_SB);
	}
}
