/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttoari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:33:15 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 13:01:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lsttoari(t_list *lst)
{
	int idx;
	int size;
	int *arr;

	idx = 0;
	arr = NULL;
	if (lst)
	{
		size = ft_lstlen(lst);
		arr = ft_memalloc(size * sizeof(int));
		if (arr)
		{
			while (lst)
			{
				arr[idx++] = *(int*)lst->content;
				lst = lst->next;
			}
		}
	}
	return (arr);
}
