/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:28:33 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/04 13:28:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_median(t_list *lst)
{
	int *arr;
	int	size;
	int median;

	median = -42;
	if (lst)
	{
		arr = lsttoari(lst);
        if (arr)
        {
            size = ft_lstlen(lst) - 1;
            median = arr_quickselect(arr, 0, size, (size / 2) + 1);
            free(arr);
        }
    }
	return (median);
}