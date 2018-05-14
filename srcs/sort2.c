/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:26:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 11:27:55 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **lst1, t_list **lst2)
{
	int a;
	int b;

	a = *(int*)(*lst1)->content;
	b = *(int*)(*lst1)->next->content;
	if (a > b)
		op_execute_swap_opt(lst1, lst2, 'a');
}
