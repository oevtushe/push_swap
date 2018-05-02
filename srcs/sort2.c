/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:26:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 17:26:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack **a_stack, t_stack **b_stack)
{
	int a;
	int b;

	a = *(int*)(*a_stack)->lst->content;
	b = *(int*)(*a_stack)->lst->next->content;
	if (a > b)
		op_execute_swap_opt(&(*a_stack)->lst, &(*b_stack)->lst);
}
