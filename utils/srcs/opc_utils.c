/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:50:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 12:00:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	del_opc(void *content, size_t content_size)
{
	t_opc *opc;

	opc = (t_opc*)content;
	free_opc(&opc);
	++content_size;
}

void	free_opc(t_opc **opc)
{
	if (opc && *opc)
	{
		ft_strdel(&(*opc)->op_name);
		ft_memdel((void**)opc);
	}
}

t_opc	*new_opc(t_operation op, char *op_name)
{
	t_opc	*opc;

	opc = ft_memalloc(sizeof(t_opc));
	opc->abbr = op;
	opc->op_name = op_name;
	return (opc);
}

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
