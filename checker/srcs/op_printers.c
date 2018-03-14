/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:09:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 10:30:18 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_swap(t_list **a, t_list **b, void (*pf)(t_list **a, t_list **b, char *color))
{
	pf(a, b, RED);
	pf(a, b, RED);
}

void		print_sswap(t_list **a, t_list **b)
{
	print_crow(a, b, RED);
	print_crow(a, b, RED);
}
