/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nmedian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/16 09:00:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Split substack with specified size by median .
**
** @param	size	size of substack.
** @param	ngrp	separated group number.
*/

void		split_nmedian(t_stack **stack1, t_stack **stack2, int size, int ngrp)
{
	int		median;
	int		rot_cnt;

	rot_cnt = 0;
	median = find_nmedian((*stack1)->lst, size);
	ft_printf("median = %d\n", median);
	while (size--)
	{
		if (*(int*)(*stack1)->lst->content < median)
		{
			(*stack1)->lst->content_size = ngrp;
			op_execute_wrp(&(*stack1)->lst, &(*stack2)->lst, OP_PB);
		}
		else
		{
			++rot_cnt;
			op_execute_wrp(&(*stack1)->lst, NULL, OP_RA);
		}
	}
}
