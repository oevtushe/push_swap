/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprint_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:49:17 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/24 09:49:51 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_int(t_list *elem)
{
	ft_printf("elem: %d\ngroup: %zu\n\n", *(int*)elem->content, elem->content_size);
}

void		dprint_stacks(t_stack *a, t_stack *b)
{
	ft_lstiter(a->lst, print_int);
	ft_printf("-----\n\n");
	ft_lstiter(b->lst, print_int);
}
