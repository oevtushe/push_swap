/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:32:48 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:05:24 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		free_int_map(&map, map_size.first);
	}
	else if (ops_a)
		res = ft_lstmap(ops_a, cpy_a);
	else if (ops_b)
		res = ft_lstmap(ops_b, cpy_b);
	return (res);
}

void			sort3_new(t_stacks *stacks, int fd)
{
	t_list	*ops_a;
	t_list	*ops_b;
	t_list	*res;
	t_opc	*opc;
	t_list	*rn;

	res = NULL;
	ops_a = gen_op_sort3(get_comb_a(stacks->a), 1);
	ops_b = gen_op_sort3(get_comb_b(stacks->b), -1);
	res = combine_opts(ops_a, ops_b);
	ft_lstiter(res, opc_lst_rebase);
	ft_lstcorder(&res);
	rn = res;
	while (rn)
	{
		opc = (t_opc*)rn->content;
		op_execute_wrp(stacks, opc->abbr, fd);
		rn = rn->next;
	}
	ft_lstdel(&ops_a, del_simple);
	ft_lstdel(&ops_b, del_simple);
	ft_lstdel(&res, del_opc);
}
