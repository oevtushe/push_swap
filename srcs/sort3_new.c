/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:32:48 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 10:42:02 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		append_a(t_list *elem)
{
	ft_strconnect((char**)&elem->content, "a", 1);
	elem->content_size++;
}

static void		append_b(t_list *elem)
{
	ft_strconnect((char**)&elem->content, "b", 1);
	elem->content_size++;
}

static t_list	*combine_opts(t_list *ops_a, t_list *ops_b)
{
	int		**map;
	t_list	*res;
	t_pair	map_size;

	res = NULL;
	if (ops_a && ops_b)
	{
		map = gen_map(ops_a, ops_b, &map_size);
		ft_lstiter(ops_a, append_a);
		ft_lstiter(ops_b, append_b);
		res = create_opt_op_lst(map, &map_size, ops_a, ops_b);
	}
	else if (ops_a)
	{
		ft_lstiter(ops_a, append_a);
		res = ops_a;
	}
	else if (ops_b)
	{
		ft_lstiter(ops_b, append_b);
		res = ops_b;
	}
	return (res);
}

void			sort3_new(t_stacks *stacks)
{
	t_list	*ops_a;
	t_list	*ops_b;
	t_list	*res;
	t_opc	*opc;

	res = NULL;
	ops_a = gen_op_sort3(get_comb_a(stacks->a), 1);
	ops_b = gen_op_sort3(get_comb_b(stacks->b), -1);
	res = combine_opts(ops_a, ops_b);
	ft_lstiter(res, nm_to_opc);
	ft_lstcorder(&res);
	while (res)
	{
		opc = (t_opc*)res->content;
		op_execute_wrp(stacks, opc->abbr);
		res = res->next;
	}
}
