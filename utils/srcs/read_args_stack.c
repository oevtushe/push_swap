/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:57:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:26:32 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list_de	*read_args_stack(char **data, int size)
{
	int			cnt;
	int			val;
	t_list_de	*lst;
	t_list_de	*cur;

	cnt = size;
	lst = NULL;
	if (data && *data)
	{
		while (cnt--)
		{
			val = ft_atoi(data[cnt]);
			cur = ft_lstnew_de(&val, sizeof(int));
			ft_lstadd_de(&lst, cur);
		}
	}
	return (lst);
}
