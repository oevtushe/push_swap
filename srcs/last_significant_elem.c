/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_significant_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:33:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/24 11:30:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			last_bigger_elem(t_stack **stack, int grp, int n)
{
	int		i;
	int		pos;
	t_list *lst;

	i = 0;
	pos = -2;
	lst = (*stack)->lst;
	while (lst && (int)lst->content_size == grp)
	{
		if (*(int*)lst->content >= n)
			pos = i;
		++i;
		lst = lst->next;
	}
	return (pos + 1);
}

int			last_less_elem(t_stack **stack, int grp, int n)
{
	int		i;
	int		pos;
	t_list *lst;

	i = 0;
	pos = -2;
	lst = (*stack)->lst;
	while (lst && (int)lst->content_size == grp)
	{
		if (*(int*)lst->content < n)
			pos = i;
		++i;
		lst = lst->next;
	}
	return (pos + 1);
}
