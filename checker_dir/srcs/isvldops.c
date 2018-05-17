/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvldops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:30:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:10:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			is_vldop(char *op)
{
	if (ft_strequ(op, "sa"))
		return (1);
	else if (ft_strequ(op, "sb"))
		return (1);
	else if (ft_strequ(op, "ss"))
		return (1);
	else if (ft_strequ(op, "pa"))
		return (1);
	else if (ft_strequ(op, "pb"))
		return (1);
	else if (ft_strequ(op, "ra"))
		return (1);
	else if (ft_strequ(op, "rb"))
		return (1);
	else if (ft_strequ(op, "rr"))
		return (1);
	else if (ft_strequ(op, "rra"))
		return (1);
	else if (ft_strequ(op, "rrb"))
		return (1);
	else if (ft_strequ(op, "rrr"))
		return (1);
	return (0);
}

int			isvldops(t_list_de *op_stack)
{
	int		vld;
	char	*op;

	vld = 0;
	while (op_stack)
	{
		op = (char *)op_stack->content;
		if (!is_vldop(op))
			break ;
		op_stack = op_stack->next;
	}
	vld = !op_stack ? 1 : 0;
	return (vld);
}
