/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_opc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:30:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 14:27:30 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_opc	*new_opc(t_operation op, char *op_name)
{
	t_opc	*opc;

	opc = ft_memalloc(sizeof(t_opc));
	opc->abbr = op;
	opc->op_name = ft_strdup(op_name);
	return (opc);
}
