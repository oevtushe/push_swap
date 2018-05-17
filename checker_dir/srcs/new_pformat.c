/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:08:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:11:47 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			stack_lil(t_list_de *a)
{
	int		max;
	int		min;
	int		lmin;
	int		lmax;

	max = *(int*)a->content;
	min = *(int*)a->content;
	while (a)
	{
		if (*(int*)a->content > max)
			max = *(int*)a->content;
		if (*(int*)a->content < min)
			min = *(int*)a->content;
		a = a->next;
	}
	lmin = ft_intln(min);
	lmax = ft_intln(max);
	if (lmin > lmax)
		return (lmin);
	return (lmax);
}

t_pformat			*new_pformat(t_list_de *a)
{
	t_pformat	*pfmt;

	pfmt = (t_pformat*)ft_memalloc(sizeof(t_pformat));
	pfmt->ba = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->bb = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->color = RED;
	pfmt->bi_ln = stack_lil(a);
	if (!(pfmt->bi_ln % 2))
		++pfmt->bi_ln;
	return (pfmt);
}

