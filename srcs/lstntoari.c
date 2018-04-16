/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstntoari.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:35:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/13 10:35:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** If size is > list size you'll get NULL. Admit it.
*/

int     *lstntoari(t_list *lst, int size)
{
    int idx;
    int *arr;

    idx = 0;
    arr = NULL;
    if (lst && size <= (int)ft_lstlen(lst))
    {
        arr = ft_memalloc(size * sizeof(int));
        if (arr)
        {
            while (idx < size)
            {
                arr[idx++] = *(int*)lst->content;
                lst = lst->next;
            }
        }
    }
    return (arr);
}