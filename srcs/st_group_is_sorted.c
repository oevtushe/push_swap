/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_group_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:12:11 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:44:18 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		st_group_is_sorted(t_list *lst)
{
	int prev;
	int	cg;

	if (lst)
	{
		cg = (int)lst->content_size;
		prev = *(int*)lst->content;
		while (lst && prev <= *(int*)lst->content\
				&& (int)lst->content_size == cg)
		{
			prev = *(int*)lst->content;
			lst = lst->next;
		}
		if (!lst)
			return (1);
		return ((int)lst->content_size != cg ? 1 : 0);
	}
	return (0);
}
