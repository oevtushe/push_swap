/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:09:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/15 10:24:24 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_swap(t_list **a, t_list **b, void (*pf)(t_list **a, t_list **b, char *color))
{
	pf(a, b, RED);
	pf(a, b, RED);
}

void		print_crow_st(t_list **a, t_list **b, t_excstat stat)
{
	if (stat == ES_AM)
		print_crow_a(a, b, RED);
	else if (stat == ES_BM)
		print_crow_b(a, b, RED);
	else if (stat == ES_BOTH)
		print_crow(a, b, RED);
}

void		print_sswap(t_list **a, t_list **b, t_excstat stat)
{
	print_crow_st(a, b, stat);
	print_crow_st(a, b, stat);
}
