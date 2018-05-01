/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:08:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/01 13:36:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			stack_max_int_len(t_list *a)
{
	int		max;

	max = *(int*)a->content;
	while (a)
	{
		if (*(int*)a->content > max)
			max = *(int*)a->content;
		a = a->next;
	}
	return (ft_intln(max));
}

t_pformat			*new_pformat(t_list *a)
{
	t_pformat	*pfmt;

	pfmt = (t_pformat*)ft_memalloc(sizeof(t_pformat));
	pfmt->ba = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->bb = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->color = RED;
	pfmt->bi_ln = stack_max_int_len(a);
	if (!(pfmt->bi_ln % 2))
		++pfmt->bi_ln;
	return (pfmt);
}

