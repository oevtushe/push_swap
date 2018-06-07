/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:08:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:46:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Functoion finds the longest int present in the stack
**
** For example "3" "21" -> "3" the longest,
**		"-21" "21" -> "-21" the longest, etc.
*/

static int			stack_lil(t_list *a)
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

/*
** Function creates and particulary initialize format structure
** with parameters such as color of output and length of the
** longest int present in stack (used for adjusting with spaces).
**
** After every operation executed 
*/

t_pformat			*new_pformat(t_list *a)
{
	t_pformat	*pfmt;

	pfmt = (t_pformat*)ft_memalloc(sizeof(t_pformat));
	pfmt->ba = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->bb = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->color = ft_strdup(RED);
	pfmt->bi_ln = stack_lil(a);
	if (!(pfmt->bi_ln % 2))
		++pfmt->bi_ln;
	pfmt->tl_ch = ' ';
	pfmt->tr_ch = ' ';
	pfmt->tmiddle_ch = '_';
	pfmt->bl_ch = '|';
	pfmt->br_ch = '|';
	pfmt->btm_middle_ch = '_';
	pfmt->btm_l_ch = '|';
	pfmt->btm_r_ch = '|';
	return (pfmt);
}
