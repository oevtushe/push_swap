/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/23 13:46:47 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(t_list *elem)
{
	ft_printf("elem: %d\ngroup: %zu\n\n", *(int*)elem->content, elem->content_size);
}

void	del_int(void *content, size_t content_size)
{
	++content_size;
	free(content);
}

int		get_group(t_stack **a, int group)
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
	t_list	*lst;
	int		rot_cnt;

	split_group_a(a, b);
	while ((*b)->lst)
		split_group_b(a, b);
	lst = (*a)->lst;
	rot_cnt = 0;
	while ((lst = get_next_group(lst)) && !rot_cnt)
	{
		if (top_grp_len(lst) > 3)
			rot_cnt = get_group(a, lst->content_size);
	}
	if (rot_cnt)
		sort_stacks(a, b);
	while (rot_cnt--)
		op_execute_wrp(&(*a)->lst, NULL, OP_RRA);
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
	sort_stacks(&a, &b);
/*
	ft_lstiter(a->lst, print_int);
	ft_printf("-----\n\n");
	ft_lstiter(b->lst, print_int);
*/
/*
	split_group_a(&a, &b);
	ft_lstiter(a->lst, print_int);
	ft_printf("-----\n\n");
	ft_lstiter(b->lst, print_int);
	if (b->lst)
		split_group_b(&a, &b);
	if (b->lst)
		split_group_b(&a, &b);
	ft_lstiter(a->lst, print_int);
	ft_printf("-----\n\n");
	ft_lstiter(b->lst, print_int);
*/
	free_str_arr(&arr, size);
	return (0);
}
