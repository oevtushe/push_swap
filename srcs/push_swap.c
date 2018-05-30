/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/30 18:17:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_int(void *content, size_t content_size)
{
	++content_size;
	free(content);
}

void	sort_stacks(t_stacks *stacks)
{
	int		group_cnt;

	group_cnt = 0;
	split_group_a(stacks, &group_cnt);
	while (stacks->b)
		split_group_b(stacks, &group_cnt);
}

int		main(int argc, char **argv)
{
	t_list		*a;
	t_stacks	*stacks;
	char		**arr;
	int			size;

	a = NULL;
	if (argc < 2)
		return (1);
	arr = split_arr(&argv[1], argc - 1, &size);
	if (isvldarg(arr, size))
		a = read_args_stack(arr, size);
	else
		ps_error("Error\n");
	rebase_lst_data(a);
	stacks = new_stacks(a, NULL);
	if (!st_issorted(a))
		sort_stacks(stacks);
	free_str_arr(&arr, size);
	return (0);
}
