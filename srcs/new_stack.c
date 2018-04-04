/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:56:21 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/02 11:56:27 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(t_list *lst, char name)
{
	t_stack *stack;

	stack = ft_memalloc(sizeof(t_stack));
	if (stack)
	{
		stack->lst = lst;
		stack->name = name;
	}
	return (stack);
}