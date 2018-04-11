/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:54:14 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/11 09:54:22 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_group	*split_median(t_group *gr)
{
	int		median;
	int		rot_cnt;
	t_group	*ng;
	int		cnt;

	cnt = ft_lstlen(gr->stack);
	rot_cnt = 0;
	ng = new_group(gr->gr_id + 1, NULL);
	median = find_median(gr->stack);
	ft_printf("median = %d\n", median);
	while (cnt--)
	{
		if (*(int *)gr->stack->content < median)
		{
			op_execute(&gr->stack, &ng->stack, OP_PB);
			ft_printf("pb\n");
		}
		else
		{
			++rot_cnt;
			op_execute(&gr->stack, NULL, OP_RA);
			ft_printf("ra\n");
		}
	}
	return (ng);
}