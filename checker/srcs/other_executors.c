/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:45:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 14:46:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_swap(t_list *stack)
{
	void	*tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

void	execute_sswap(t_list *a, t_list *b)
{
	execute_swap(a);
	execute_swap(b);
}

void	execute_push(t_list **fst, t_list **scd)
{
	void	*tmp;

	if (scd && *scd)
	{
		tmp = (*scd)->next;
		ft_lstadd(fst, *scd);
		*scd = tmp;
	}
}
