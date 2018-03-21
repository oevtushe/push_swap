/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:01:07 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 17:07:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*read_args_stack(char **data, int size)
{
	int		cnt;
	int		val;
	t_list	*lst;
	t_list	*cur;

	cnt = size;
	lst = NULL;
	if (data && *data)
	{
		while (cnt--)
		{
			val = ft_atoi(data[cnt]);
			cur = ft_lstnew(&val, sizeof(int));
			ft_lstadd(&lst, cur);
		}
	}
	return (lst);
}
