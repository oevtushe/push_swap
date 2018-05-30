/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_op_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:08:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/30 11:10:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_opc				*get_opc(char *oper_nm)
{
	if (ft_strequ(oper_nm, "sa"))
		return (new_opc(OP_SA, oper_nm));
	else if (ft_strequ(oper_nm, "sb"))
		return (new_opc(OP_SB, oper_nm));
	else if (ft_strequ(oper_nm, "ss"))
		return (new_opc(OP_SS, oper_nm));
	else if (ft_strequ(oper_nm, "pa"))
		return (new_opc(OP_PA, oper_nm));
	else if (ft_strequ(oper_nm, "pb"))
		return (new_opc(OP_PB, oper_nm));
	else if (ft_strequ(oper_nm, "ra"))
		return (new_opc(OP_RA, oper_nm));
	else if (ft_strequ(oper_nm, "rb"))
		return (new_opc(OP_RB, oper_nm));
	else if (ft_strequ(oper_nm, "rr"))
		return (new_opc(OP_RR, oper_nm));
	else if (ft_strequ(oper_nm, "rra"))
		return (new_opc(OP_RRA, oper_nm));
	else if (ft_strequ(oper_nm, "rrb"))
		return (new_opc(OP_RRB, oper_nm));
	else if (ft_strequ(oper_nm, "rrr"))
		return (new_opc(OP_RRR, oper_nm));
	return (NULL);
}

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
