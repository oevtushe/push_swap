/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_lst_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:17:29 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/12 16:17:32 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** content_size -> group number
*/

void		rebase_lst_data(t_list *lst)
{
	while (lst)	
	{
		lst->content_size = 1;
		lst = lst->next;
	}
}
