/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:57:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/02 17:57:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fuck_init_push(t_opc *opc, char which)
{
	if (which == 'a')
	{
		opc->abbr = OP_PB;	
		opc->op_name = "pb";
	}
	else
	{
		opc->abbr = OP_PA;
		opc->op_name = "pa";
	}
}

/*
** The higher element will be selected as a median.
*/

int		st_separate(t_stack **a, t_stack **b, t_bounds bounds, char which)
{
	int		idx;
	int		median;
	int		pushed;
	t_opc	p;
	int		(*cmp)(int v1, int v2);

	if (which == 'a')
		cmp = lmiddle_cmp;
	else
		cmp = hmiddle_cmp;
	fuck_init_push(&p, which);
	pushed = 0;
	median = lst_quickselect(a, bounds.p, bounds.r, ((bounds.r - bounds.p) / 2) + 1);
	ft_printf("median = %d\n", median);
	idx = -1;
	while (++idx <= bounds.r)
	{
		if (cmp(lstgeti((*a)->lst, idx), median))
		{
			push_exec_pr(a, b, p);
			++pushed;
		}
	}
	return (pushed);
}