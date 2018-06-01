/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:26:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 11:11:00 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stacks *stacks, int fd)
{
	int a;
	int b;

	a = *(int*)stacks->a->content;
	b = *(int*)stacks->a->next->content;
	if (a > b)
		op_execute_swap_opt(stacks, 'a', fd);
}
