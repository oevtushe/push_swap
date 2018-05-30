/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_swap_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:48:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/30 15:44:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_execute_swap_opt(t_stacks *stacks, char stack)
{
	int done;

	done = 0;
	if (stacks->b)
	{
		if (top_grp_len(stacks->b) == 2 &&
				*(int*)stacks->b->content < *(int*)stacks->b->next->content)
		{
			op_execute_wrp(stacks, OP_SS);
			done = 1;
		}
	}
	if (!done)
	{
		if (stack == 'a')
			op_execute_wrp(stacks, OP_SA);
		else
			op_execute_wrp(stacks, OP_SB);
	}
}
