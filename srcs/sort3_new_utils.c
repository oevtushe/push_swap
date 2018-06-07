/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_new_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:04:57 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:05:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		append_a(t_list *elem)
{
	ft_strconnect((char**)&elem->content, "a", 1);
	elem->content_size++;
}

void		append_b(t_list *elem)
{
	ft_strconnect((char**)&elem->content, "b", 1);
	elem->content_size++;
}

void		free_int_map(int ***map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void**)&(*map)[i]);
		++i;
	}
	ft_memdel((void**)map);
}

t_list		*cpy_b(t_list *elem)
{
	t_list	*new;
	char	*str;

	str = ft_strjoin((char*)elem->content, "b");
	new = ft_lstnew(str, ft_strlen(str) + 1);
	ft_strdel(&str);
	return (new);
}

t_list		*cpy_a(t_list *elem)
{
	t_list	*new;
	char	*str;

	str = ft_strjoin((char*)elem->content, "a");
	new = ft_lstnew(str, ft_strlen(str) + 1);
	ft_strdel(&str);
	return (new);
}
