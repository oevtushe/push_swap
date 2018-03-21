/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:06:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 10:46:51 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_row(t_list **a, t_list **b)
{
	if (a && *a)
	{
		ft_printf("%d", *(int*)(*a)->content);
		*a = (*a)->next;
	}
	else
		ft_printf(" ");
	if (b && *b)
	{
		ft_printf("%5d\n", *(int*)(*b)->content);
		*b = (*b)->next;
	}
	else
		ft_printf("%5s\n", " ");
}

void		print_crow_a(t_list **a, t_list **b, char *color)
{
	if (a && *a)
	{
		ft_printf("%s%d%s", color, *(int*)(*a)->content, RESET);
		*a = (*a)->next;
	}
	else
		ft_printf(" ");
	if (b && *b)
	{
		ft_printf("%5d\n", *(int*)(*b)->content);
		*b = (*b)->next;
	}
	else
		ft_printf("%5s\n", " ");
}

void		print_crow_b(t_list **a, t_list **b, char *color)
{
	if (a && *a)
	{
		ft_printf("%d", *(int*)(*a)->content);
		*a = (*a)->next;
	}
	else
		ft_printf(" ");
	if (b && *b)
	{
		ft_printf("%s%5d%s\n", color, *(int*)(*b)->content, RESET);
		*b = (*b)->next;
	}
	else
		ft_printf("%5s\n", " ");
}

void		print_crow(t_list **a, t_list **b, char *color)
{
	if (a && *a)
	{
		ft_printf("%s%d%s", color, *(int*)(*a)->content, RESET);
		*a = (*a)->next;
	}
	else
		ft_printf(" ");
	if (b && *b)
	{
		ft_printf("%s%5d%s\n", color, *(int*)(*b)->content, RESET);
		*b = (*b)->next;
	}
	else
		ft_printf("%5s\n", " ");
}
