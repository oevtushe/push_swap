/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfmt_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:17:57 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 11:42:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_bottom(t_bottom **bottom)
{
	if (bottom && *bottom)
	{
		if ((*bottom)->name)
			ft_strdel(&(*bottom)->name);
		if ((*bottom)->separator)
			ft_strdel(&(*bottom)->separator);
		ft_memdel((void**)bottom);
	}
}

void	free_pfmt(t_pformat **pfmt)
{
	if (pfmt && *pfmt)
	{
		free_bottom(&(*pfmt)->ba);
		free_bottom(&(*pfmt)->bb);
		ft_strdel(&(*pfmt)->color);
		ft_memdel((void**)pfmt);
	}
}

void	pfmt_prep_to_next(t_pformat *pfmt)
{
	if (pfmt)
	{
		if (pfmt->ba)
		{
			ft_strdel(&pfmt->ba->name);
			ft_strdel(&pfmt->ba->separator);
		}
		if (pfmt->bb)
		{
			ft_strdel(&pfmt->bb->name);
			ft_strdel(&pfmt->bb->separator);
		}
	}
}
