/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_quickselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:37:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/04 12:37:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(t_stack **stack, int p, int r)
{
	int		i;
	int		j;
	int		pivot;

	pivot = lstgeti((*stack)->lst, r);
	i = p - 1;
	j = p;
	while (j < r)
	{
		if (lstgeti((*stack)->lst, j) <= pivot)
		{
			++i;
			lst_safe_swap(stack, i, j);
		}
		++j;
	}
	lst_safe_swap(stack, i + 1, r);
	return (i + 1);
}

int			lst_quickselect(t_stack **stack, int p, int r, int i)
{
	int q;
	int k;

	if (p == r)
		return (lstgeti((*stack)->lst, p));
	q = partition(stack, p, r);	
	k = q - p + 1;
	if (i == k)
		return (lstgeti((*stack)->lst, q));
	else if (i < k)
		return (lst_quickselect(stack, p, q - 1, i));
	else
		return (lst_quickselect(stack, q + 1, r, i - k));
}
