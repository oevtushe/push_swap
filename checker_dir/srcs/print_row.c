/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:32:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:12:32 by oevtushe         ###   ########.fr       */
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

static void	print_elem_a(t_list_de **a, t_pformat *pfmt)
{
	if (a && *a)
	{
		if (pfmt->stat == ES_AM || pfmt->stat == ES_BOTH)
			ft_printf("|%s%-*d%s|", pfmt->color, 
					pfmt->bi_ln, *(int*)(*a)->content, RESET);
		else
			ft_printf("|%-*d|", pfmt->bi_ln, *(int*)(*a)->content);
		*a = (*a)->next;
	}
	else
		empty_a(pfmt);
}

static void	print_elem_b(t_list_de **b, t_pformat *pfmt)
{
	if (b && *b)
	{
		if (pfmt->stat == ES_BM || pfmt->stat == ES_BOTH)
			ft_printf("%*s|%s%*d%s|\n", pfmt->spcs, " ", 
					pfmt->color, pfmt->bi_ln, *(int*)(*b)->content, RESET);
		else
			ft_printf("%*s|%*d|\n", pfmt->spcs, " ", 
					pfmt->bi_ln, *(int*)(*b)->content);
		*b = (*b)->next;
	}
	else
		empty_b(pfmt);
}

void		print_row(t_list_de **a, t_list_de **b, t_pformat *pfmt)
{
	print_elem_a(a, pfmt);
	print_elem_b(b, pfmt);
}
