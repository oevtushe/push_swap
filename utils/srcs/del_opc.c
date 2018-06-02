/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_opc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:23:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/02 10:24:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	del_opc(void *content, size_t content_size)
{
	t_opc *opc;

	++content_size;
	opc = (t_opc*)content;
	free(opc->op_name);
	free(opc);
}
