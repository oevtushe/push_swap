/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 11:12:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** C
** B
** A
*/

static void	sort_CBA(t_stacks *stacks, int fd)
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

static void	sort_CAB(t_stacks *stacks, int fd)
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

static void	sort_BCA(t_stacks *stacks, int fd)
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

static void	sort_ACB(t_stacks *stacks, int fd)
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
		sort_CBA(stacks, fd);
	else if (a > b && a > c && b < c)
		sort_CAB(stacks, fd);
	else if (a < b && c < b && a < c)
		sort_ACB(stacks, fd);
	else if (a < b && c < b && a > c)
		sort_BCA(stacks, fd);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a', fd);
}
