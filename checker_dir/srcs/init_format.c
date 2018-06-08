/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:19:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/08 10:22:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		init_bottom(t_pformat *pfmt, t_bottom *bottom,\
		char *st_name, int bi_ln)
{
	int		b_spaces;

	b_spaces = (bi_ln - ft_strlen(st_name)) / 2 + 1;
	bottom->name = ft_strdup(st_name);
	ft_strcntllr(&bottom->name, ft_strlen(bottom->name) + b_spaces, ' ', -1);
	ft_strcntllr(&bottom->name, ft_strlen(bottom->name) + b_spaces, ' ', 1);
	bottom->separator = ft_strnew(bi_ln + 2);
	ft_memset(bottom->separator, pfmt->ufmt.btmm, bi_ln + 2);
	bottom->separator[0] = pfmt->ufmt.btml;
	bottom->separator[bi_ln + 1] = pfmt->ufmt.btmr;
	bottom->is_sp_printed = 0;
	bottom->is_nm_printed = 0;
}

/*
** Function initializes pretty stacks print format depending on
** the longest int in the stack.
**
** The length between the stacks depends on the length of operation
** name, so the pformat is needed to be reinitialized every new
** operation executed.
*/

void			init_format(t_pformat *pfmt, char *op_name, t_excstat stat)
{
	pfmt->spcs = 12 + ft_strlen(op_name) + 1;
	pfmt->stat = stat;
	init_bottom(pfmt, pfmt->ba, "a", pfmt->bi_ln);
	init_bottom(pfmt, pfmt->bb, "b", pfmt->bi_ln);
	ft_strcntllr(&pfmt->bb->separator,
			ft_strlen(pfmt->bb->separator) + pfmt->spcs, ' ', -1);
	ft_strcntllr(&pfmt->bb->name,
			ft_strlen(pfmt->bb->name) + pfmt->spcs, ' ', -1);
}
