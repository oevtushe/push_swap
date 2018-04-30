/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:32:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/30 18:01:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_row(t_list **a, t_list **b, t_pformat *pfmt)
{
	char	*tmp;

	if (a && *a)
	{
		if (pfmt->stat == ES_AM || pfmt->stat == ES_BOTH)
		{
			tmp = str_join_number("|%s%-", pfmt->bi_ln, "d%s|");
			ft_printf(tmp, pfmt->color, *(int*)(*a)->content, RESET);
		}
		else
		{
			tmp = str_join_number("|%-", pfmt->bi_ln, "d|");
			ft_printf(tmp, *(int*)(*a)->content);
		}
		free(tmp);
		*a = (*a)->next;
	}
	else
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
		{
			tmp = str_join_number("%", pfmt->bi_ln + 2, "s");
			ft_printf(tmp, " ");
		}
	}
	if (b && *b)
	{
		if (pfmt->stat == ES_BM || pfmt->stat == ES_BOTH)
		{
			tmp = str_join_number("|%s%", pfmt->bi_ln, "d%s|\n");
			ft_strcntllr(&tmp, ft_strlen(tmp) + pfmt->spcs, ' ', -1);
			ft_printf(tmp, pfmt->color, *(int*)(*b)->content, RESET);
		}
		else
		{
			tmp = str_join_number("|%", pfmt->bi_ln, "d|\n");
			ft_strcntllr(&tmp, ft_strlen(tmp) + pfmt->spcs, ' ', -1);
			ft_printf(tmp, *(int*)(*b)->content);
		}
		*b = (*b)->next;
		free(tmp);
	}
	else
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
}
