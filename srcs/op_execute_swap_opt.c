/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execute_swap_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:48:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 18:04:53 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_execute_swap_opt(t_stacks *stacks, char stack, int fd)
{
	int done;

	done = 0;
	if (stacks->b)
	{
		if (top_grp_len(stacks->b) == 2 &&
				*(int*)stacks->b->content < *(int*)stacks->b->next->content)
		{
			op_execute_wrp(stacks, OP_SS, fd);
			done = 1;
		}
	}
	if (!done)
	{
		if (stack == 'a')
			op_execute_wrp(stacks, OP_SA, fd);
		else
			op_execute_wrp(stacks, OP_SB, fd);
	}
}
