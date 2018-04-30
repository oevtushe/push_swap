/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:32:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/30 15:32:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_row(t_list **a, t_list **b, t_pformat *pfmt)
{
	if (a && *a)
	{
		if (pfmt->stat == ES_AM || pfmt->stat == ES_BOTH)
			ft_printf("%s%d%s", pfmt->color, *(int*)(*a)->content, RESET);
		else
			ft_printf("%d", *(int*)(*a)->content);
		*a = (*a)->next;
	}
	else
		ft_printf(" ");
	if (b && *b)
	{
		if (pfmt->stat == ES_BM || pfmt->stat == ES_BOTH)
			ft_printf("%s%5d%s\n", pfmt->color, *(int*)(*b)->content, RESET);
		else
			ft_printf("%5d\n", *(int*)(*b)->content);
		*b = (*b)->next;
	}
	else
		ft_printf("%5s\n", " ");
}
