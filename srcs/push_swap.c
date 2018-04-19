/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/19 10:59:16 by oevtushe         ###   ########.fr       */
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

int		top_grp_len(t_list *lst)
{
	int		len;
	size_t	cur_grp;

	len = 0;
	cur_grp = lst->content_size;
	while (lst && lst->content_size == cur_grp)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

void	split_group(t_stack **stack1, t_stack **stack2)
{
	t_list	*lst1;
	t_list	*lst2;
	int		top_len;
	int		grp_cnt;

	lst1 = (*stack1)->lst;
	lst2 = (*stack2)->lst;
	grp_cnt = (int)(*stack1)->lst->content_size;
	while ((top_len = top_grp_len((*stack1)->lst)) > 3)
	{
		++grp_cnt;
		split_nmedian(stack1, stack2, top_len, grp_cnt);
	}
	if (top_len == 3)
		sort3(stack1);
	else
		sort2(stack1);
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
	split_group(&a, &b);
	ft_lstiter(a->lst, print_int);
	ft_printf("-----\n\n");
	ft_lstiter(b->lst, print_int);
	free_str_arr(&arr, size);
	return (0);
}
