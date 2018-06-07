/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_op_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:07:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:08:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** C
** B
** A
*/

static void	sort_cba(t_list **ops)
{
	t_list *node;

	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("r", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("rr", 3);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
}

/*
** C
** A
** B
*/

static void	sort_cab(t_list **ops)
{
	t_list *node;

	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("r", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("rr", 3);
	ft_lstadd(ops, node);
}

/*
** B
** C
** A
*/

static void	sort_bca(t_list **ops)
{
	t_list *node;

	node = ft_lstnew("r", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("rr", 3);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
}

/*
** A
** C
** B
*/

static void	sort_acb(t_list **ops)
{
	t_list *node;

	node = ft_lstnew("r", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("rr", 3);
	ft_lstadd(ops, node);
}

t_list		*gen_op_sort3(t_comb comb, int order)
{
	t_list *ops;

	ops = NULL;
	if ((comb == CBA && order > 0) || (comb == ABC && order < 0))
		sort_cba(&ops);
	else if ((comb == CAB && order > 0) || (comb == ACB && order < 0))
		sort_cab(&ops);
	else if ((comb == BCA && order > 0) || (comb == BAC && order < 0))
		sort_bca(&ops);
	else if ((comb == ACB && order > 0) || (comb == CAB && order < 0))
		sort_acb(&ops);
	else if ((comb == BAC && order > 0) || (comb == BCA && order < 0))
		ft_lstadd(&ops, ft_lstnew("s", 2));
	return (ops);
}
