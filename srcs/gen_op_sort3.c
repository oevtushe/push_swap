/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_op_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:07:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/30 18:04:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** C
** B
** A
*/

static void	sort_CBA(t_list **ops)
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

static void	sort_CAB(t_list **ops)
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

static void	sort_BCA(t_list **ops)
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

static void	sort_ACB(t_list **ops)
{
	t_list *node;

	node = ft_lstnew("r", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("s", 2);
	ft_lstadd(ops, node);
	node = ft_lstnew("rr", 3);
	ft_lstadd(ops, node);
}

t_list	*gen_op_sort3(t_comb comb, int order)
{
	t_list *ops;

	ops = NULL;
	if ((comb == CBA && order > 0) || (comb == ABC && order < 0))
		sort_CBA(&ops);
	else if ((comb == CAB && order > 0) || (comb == ACB && order < 0))
		sort_CAB(&ops);
	else if ((comb == BCA && order > 0) || (comb == BAC && order < 0))
		sort_BCA(&ops);
	else if ((comb == ACB && order > 0) || (comb == CAB && order < 0))
		sort_ACB(&ops);
	else if ((comb == BAC && order > 0) || (comb == BCA && order < 0))
		ft_lstadd(&ops, ft_lstnew("s", 2));
	return (ops);
}
