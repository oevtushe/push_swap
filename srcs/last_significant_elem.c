/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_significant_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:33:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/03 17:08:05 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			last_bigger_elem(t_list *lst, int grp, int n)
{
	int		i;
	int		pos;

	i = 0;
	pos = -2;
	while (lst && (int)lst->content_size == grp)
	{
		if (*(int*)lst->content >= n)
			pos = i;
		++i;
		lst = lst->next;
	}
	return (pos + 1);
}

int			last_less_elem(t_list *lst, int grp, int n)
{
	int		i;
	int		pos;

	i = 0;
	pos = -2;
	while (lst && (int)lst->content_size == grp)
	{
		if (*(int*)lst->content < n)
			pos = i;
		++i;
		lst = lst->next;
	}
	return (pos + 1);
}
