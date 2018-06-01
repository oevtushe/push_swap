/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:49:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 10:45:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_stacks	*new_stacks(t_list *a, t_list *b)
{
	t_stacks *stacks;

	stacks = ft_memalloc(sizeof(t_stacks));
	stacks->a = a;
	stacks->b = b;
	return (stacks);
}
