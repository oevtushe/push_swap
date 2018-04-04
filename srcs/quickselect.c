/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:38:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/02 16:38:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(t_stack **stack, int p, int r)
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
			swap(stack, i, j);
		}
		++j;
	}
	swap(stack, i + 1, r);
	return (i + 1);
}

int		quickselect(t_stack **stack, int p, int r, int i)
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
		return (quickselect(stack, p, q - 1, i));
	else
		return (quickselect(stack, q + 1, r, i - k));
}