/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:57:47 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 11:59:29 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_stacks(t_stacks **stacks)
{
	ft_lstdel(&(*stacks)->a, del_simple);
	ft_lstdel(&(*stacks)->b, del_simple);
	ft_memdel((void**)stacks);
	*stacks = NULL;
}

t_stacks	*new_stacks(t_list *a, t_list *b)
{
	t_stacks *stacks;

	stacks = (t_stacks*)ft_memalloc(sizeof(t_stacks));
	if (stacks)
	{
		stacks->a = a;
		stacks->b = b;
	}
	return (stacks);
}
