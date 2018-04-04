/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_exec_pr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 09:43:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/03 09:43:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_exec_pr(t_stack **st1, t_stack **st2, t_opc opc)
{
	ft_printf("%s\n", opc.op_name);
	op_execute(&(*st1)->lst, &(*st2)->lst, opc.abbr);
}