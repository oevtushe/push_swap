/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:32:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 16:06:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	empty_a(t_pformat *pfmt)
{
	if (!pfmt->ba->is_sp_printed)
	{
		ft_putstr(pfmt->ba->separator);
		pfmt->ba->is_sp_printed = 1;
	}
	else if (!pfmt->ba->is_nm_printed)
	{
		ft_putstr(pfmt->ba->name);
		pfmt->ba->is_nm_printed = 1;
	}
	else
		ft_printf("%*s", pfmt->bi_ln + 2, " ");
}

static void	empty_b(t_pformat *pfmt)
{
	if (!pfmt->bb->is_sp_printed)
	{
		ft_putstr(pfmt->bb->separator);
		pfmt->bb->is_sp_printed = 1;
	}
	else if (!pfmt->bb->is_nm_printed)
	{
		ft_putstr(pfmt->bb->name);
		pfmt->bb->is_nm_printed = 1;
	}
	ft_putchar('\n');
}

static void	print_elem_a(t_list **a, t_pformat *pfmt)
{
	if (a && *a)
	{
		if (pfmt->stat == ES_AM || pfmt->stat == ES_BOTH)
			ft_printf("%c%s%-*d%s%c", pfmt->bl_ch, pfmt->color,
					pfmt->bi_ln, *(int*)(*a)->content, RESET, pfmt->br_ch);
		else
			ft_printf("%c%-*d%c", pfmt->bl_ch, pfmt->bi_ln, *(int*)(*a)->content, pfmt->br_ch);
		*a = (*a)->next;
	}
	else
		empty_a(pfmt);
}

static void	print_elem_b(t_list **b, t_pformat *pfmt)
{
	if (b && *b)
	{
		if (pfmt->stat == ES_BM || pfmt->stat == ES_BOTH)
			ft_printf("%*s%c%s%*d%s%c\n", pfmt->spcs, " ",
					pfmt->bl_ch, pfmt->color, pfmt->bi_ln, *(int*)(*b)->content, RESET, pfmt->br_ch);
		else
			ft_printf("%*s%c%*d%c\n", pfmt->spcs, " ",
					pfmt->bl_ch, pfmt->bi_ln, *(int*)(*b)->content, pfmt->br_ch);
		*b = (*b)->next;
	}
	else
		empty_b(pfmt);
}

void		print_row(t_stacks *stacks, t_pformat *pfmt)
{
	print_elem_a(&stacks->a, pfmt);
	print_elem_b(&stacks->b, pfmt);
}
