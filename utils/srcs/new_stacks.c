/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:32:15 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/05 17:34:53 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
