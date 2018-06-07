/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_grp_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:28:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:44:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		top_grp_len(t_list *lst)
{
	int		len;
	size_t	cur_grp;

	len = 0;
	if (lst)
	{
		cur_grp = lst->content_size;
		while (lst && lst->content_size == cur_grp)
		{
			++len;
			lst = lst->next;
		}
	}
	return (len);
}
