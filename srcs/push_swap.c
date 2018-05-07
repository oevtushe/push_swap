/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/07 17:17:31 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_int(void *content, size_t content_size)
{
	++content_size;
	free(content);
}

void	sort_stacks(t_list **lst1, t_list **lst2)
{
	int		group_cnt;

	group_cnt = 0;
	split_group_a(lst1, lst2, &group_cnt);
	while (*lst2)
		split_group_b(lst1, lst2, &group_cnt);
}

int		main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	char		**arr;
	int			size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	arr = split_arr(&argv[1], argc - 1, &size);
	if (isvldarg(arr, size))
		a = read_args_stack(arr, size);
	else
		ps_error("Error\n");
	rebase_lst_data(a);
	if (!st_issorted(a))
		sort_stacks(&a, &b);
	free_str_arr(&arr, size);
	return (0);
}
