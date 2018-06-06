/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_op_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:08:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 11:52:10 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Changes content from operation names in strings
** to container with int abbreaviature for operation and
** string representation the last one. Changes elements order.
*/

void				rebase_op_stack(t_list **op_stack)
{
	t_list		*rn;
	char		*oper_nm;

	rn = *op_stack;
	if (rn)
	{
		while (rn)
		{
			oper_nm = (char *)rn->content;
			rn->content = get_opc(oper_nm);
			rn->content_size = sizeof(t_opc);
			rn = rn->next;
		}
		ft_lstcorder(op_stack);
	}
}
