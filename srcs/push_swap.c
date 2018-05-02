/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 17:04:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_int(void *content, size_t content_size)
{
	++content_size;
	free(content);
}

int		rot_to_grp(t_stack **a, int group)
{
	int		pos;

	pos = 0;
	while ((int)(*a)->lst->content_size != group)
	{
		op_execute_wrp(&(*a)->lst, NULL, OP_RA);
		++pos;
	}
	return (pos);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		group_cnt;

	group_cnt = 0;
	split_group_a(a, b, &group_cnt);
	while ((*b)->lst)
		split_group_b(a, b, &group_cnt);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*lst;
	char		**arr;
	int			size;

	lst = NULL;
	if (argc < 2)
		return (1);
	arr = split_arr(&argv[1], argc - 1, &size);
	if (isvldarg(arr, size))
		lst = read_args_stack(arr, size);
	else
		ps_error("Error\n");
	a = new_stack(lst, 'a');
	b = new_stack(NULL, 'b');
	rebase_lst_data(lst);
	if (!st_issorted(lst))
		sort_stacks(&a, &b);
	free_str_arr(&arr, size);
	return (0);
}
