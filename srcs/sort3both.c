/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:57:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 18:09:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3
** 2
** 1
*/

static void	sort321(t_stacks *stacks, int fd)
{
	op_execute_wrp(stacks, OP_SS, fd);
	op_execute_wrp(stacks, OP_RR, fd);
	op_execute_wrp(stacks, OP_SS, fd);
	op_execute_wrp(stacks, OP_RRR, fd);
	op_execute_wrp(stacks, OP_SS, fd);
}

/*
** 3
** 1
** 2
*/

static void	sort312(t_stacks *stacks, int fd)
{
    op_execute_wrp(stacks, OP_SS, fd);
    op_execute_wrp(stacks, OP_RR, fd);
    op_execute_wrp(stacks, OP_SS, fd);
    op_execute_wrp(stacks, OP_RRR, fd);
}

/*
** 2
** 3
** 1
*/

static void	sort231(t_stacks *stacks, int fd)
{
    op_execute_wrp(stacks, OP_RR, fd);
    op_execute_wrp(stacks, OP_SS, fd);
    op_execute_wrp(stacks, OP_RRR, fd);
    op_execute_wrp(stacks, OP_SS, fd);
}

/*
** 1
** 3
** 2
*/

static void	sort132(t_stacks *stacks, int fd)
{
    op_execute_wrp(stacks, OP_RR, fd);
	op_execute_wrp(stacks, OP_SS, fd);
    op_execute_wrp(stacks, OP_RRR, fd);
}

void		sort3both(t_stacks *stacks, int fd)
{
	int a;
	int b;
	int c;

	a = *(int*)stacks->a->content;
	b = *(int*)stacks->a->next->content;
	c = *(int*)stacks->a->next->next->content;
	if (a > b && a > c && b > c)
		sort321(stacks, fd);
	else if (a > b && a > c && b < c)
		sort312(stacks, fd);
	else if (a < b && c < b && a < c)
		sort132(stacks, fd);
	else if (a < b && c < b && a > c)
		sort231(stacks, fd);
	else if (a < c && b < c && a > b)
		op_execute_swap_opt(stacks, 'a', fd);
}
