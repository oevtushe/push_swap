/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_quickselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:38:36 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:44:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *v1, int *v2)
{
	int c;

	c = *v1;
	*v1 = *v2;
	*v2 = c;
}

static int	partition(int *arr, int p, int r)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[r];
	i = p - 1;
	j = p;
	while (j < r)
	{
		if (arr[j] <= pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
		++j;
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

/*
** @param	r	last arr index.
*/

int			arr_quickselect(int *arr, int p, int r, int i)
{
	int q;
	int k;

	if (p == r)
		return (arr[p]);
	q = partition(arr, p, r);
	k = q - p + 1;
	if (i == k)
		return (arr[q]);
	else if (i < k)
		return (arr_quickselect(arr, p, q - 1, i));
	else
		return (arr_quickselect(arr, q + 1, r, i - k));
}
