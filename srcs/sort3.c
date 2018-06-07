/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:03:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** C
** B
** A
*/

static void	sort_cba(t_stacks *stacks, int fd)
{
	op_execute_swap_opt(stacks, 'a', fd);
	op_execute_wrp(stacks, OP_RA, fd);
	op_execute_wrp(stacks, OP_SA, fd);
	op_execute_wrp(stacks, OP_RRA, fd);
	op_execute_wrp(stacks, OP_SA, fd);
}

/*
** C
** A
** B
*/

static void	sort_cab(t_stacks *stacks, int fd)
{
	op_execute_swap_opt(stacks, 'a', fd);
	op_execute_wrp(stacks, OP_RA, fd);
	op_execute_wrp(stacks, OP_SA, fd);
	op_execute_wrp(stacks, OP_RRA, fd);
}

/*
** B
** C
** A
*/

static void	sort_bca(t_stacks *stacks, int fd)
{
	op_execute_wrp(stacks, OP_RA, fd);
	op_execute_swap_opt(stacks, 'a', fd);
	op_execute_wrp(stacks, OP_RRA, fd);
	op_execute_wrp(stacks, OP_SA, fd);
}

/*
** A
** C
** B
*/

static void	sort_acb(t_stacks *stacks, int fd)
{
	op_execute_wrp(stacks, OP_RA, fd);
	op_execute_swap_opt(stacks, 'a', fd);
	op_execute_wrp(stacks, OP_RRA, fd);
}

void		sort3(t_stacks *stacks, int fd)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->a->content;
	b = *(int*)stacks->a->next->content;
	c = *(int*)stacks->a->next->next->content;
	if (a > b && a > c && b > c)
		sort_cba(stacks, fd);
	else if (a > b && a > c && b < c)
		sort_cab(stacks, fd);
	else if (a < b && c < b && a < c)
		sort_acb(stacks, fd);
	else if (a < b && c < b && a > c)
		sort_bca(stacks, fd);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a', fd);
}
