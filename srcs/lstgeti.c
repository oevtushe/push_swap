/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstgeti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:35:18 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/02 14:32:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lstgeti(t_list *lst, int idx)
{
	int i;

	i = 0;
	while (lst && i < idx)
	{
		lst = lst->next;
		++i;
	}
	if (lst)
		return (*(int*)lst->content);
	return (-1);
}
