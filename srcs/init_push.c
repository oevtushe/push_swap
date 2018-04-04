/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 09:39:51 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/03 09:39:55 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push(t_stack **stack, t_opc *op)
{
	if ((*stack)->name == 'a')
	{
		op->abbr = OP_PB;
		op->op_name = "pb";
	}
	else
	{
		op->abbr = OP_PA;
		op->op_name = "pa";
	}
}