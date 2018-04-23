/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:27:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/23 13:26:29 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_next_group(t_list *lst)
{
	int		cur_grp;

	cur_grp = lst->content_size;
	while (lst && (int)lst->content_size == cur_grp)
		lst = lst->next;
	return (lst);
}
