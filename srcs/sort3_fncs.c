/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/19 13:20:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3
** 2
** 1
*/

void	sort321(t_list **a, t_list **b, int which)
{
	t_operation r;
	t_operation s;
    t_operation rr;

	s = which == 'a' ? OP_SA : OP_SB;
	r = which == 'a' ? OP_RA : OP_RB;
    rr = which == 'a' ? OP_RRA : OP_RRB;
	op_execute_wrp(a, b, s);
	op_execute_wrp(a, b, r);
	op_execute_wrp(a, b, s);
	op_execute_wrp(a, b, rr);
	op_execute_wrp(a, b, s);
}

/*
** 3
** 1
** 2
*/

void	sort312(t_list **a, t_list **b, int which)
{
    t_operation r;
    t_operation s;
    t_operation rr;

    s = which == 'a' ? OP_SA : OP_SB;
    r = which == 'a' ? OP_RA : OP_RB;
    rr = which == 'a' ? OP_RRA : OP_RRB;
    op_execute_wrp(a, b, s);
    op_execute_wrp(a, b, r);
    op_execute_wrp(a, b, s);
    op_execute_wrp(a, b, rr);
}

/*
** 2
** 1
** 3
*/

void    sort213(t_list **a, t_list **b, int which)
{
    t_operation s;

    s = which == 'a' ? OP_SA : OP_SB;
    op_execute_wrp(a, b, s);
}

/*
** 2
** 3
** 1
*/

void    sort231(t_list **a, t_list **b, int which)
{
    t_operation r;
    t_operation s;
    t_operation rr;

    s = which == 'a' ? OP_SA : OP_SB;
    r = which == 'a' ? OP_RA : OP_RB;
    rr = which == 'a' ? OP_RRA : OP_RRB;
    op_execute_wrp(a, b, r);
    op_execute_wrp(a, b, s);
    op_execute_wrp(a, b, rr);
    op_execute_wrp(a, b, s);
}

/*
** 1
** 3
** 2
*/

void    sort132(t_list **a, t_list **b, int which)
{
    t_operation r;
    t_operation s;
    t_operation rr;

    s = which == 'a' ? OP_SA : OP_SB;
    r = which == 'a' ? OP_RA : OP_RB;
    rr = which == 'a' ? OP_RRA : OP_RRB;
    op_execute_wrp(a, b, r);
    op_execute_wrp(a, b, s);
    op_execute_wrp(a, b, rr);
}
