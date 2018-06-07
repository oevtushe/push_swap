/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:41:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:41:39 by oevtushe         ###   ########.fr       */
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

void	op_execute_rot_opt(t_stacks *stacks, int *opt, int fd)
{
	if (stacks->b && *opt && !get_next_group(stacks->b))
	{
		op_execute_wrp(stacks, OP_RR, fd);
		--(*opt);
	}
	else
		op_execute_wrp(stacks, OP_RA, fd);
}
