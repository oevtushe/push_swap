/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nmedian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:42:34 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/13 11:42:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** @param	size	number of elements to split.
*/

int		find_nmedian(t_list *lst, int size)
{
	int *arr;
	int median;
	int	middle;

	median = -42;
	if (lst)
	{
		arr = lstntoari(lst, size);
        if (arr)
        {
			middle = (size / 2) + 1;
            median = arr_quickselect(arr, 0, size - 1, middle);
            free(arr);
        }
    }
	return (median);
}
