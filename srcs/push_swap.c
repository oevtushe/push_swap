/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/02 09:49:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(t_list *elem)
{
	ft_printf("%d\n", *(int*)elem->content);
}

void	sort2(t_stack **stack)
{
	lst_quickselect(stack, 0, 1, 1);
}

void	sort3(t_stack **stack)
{
	lst_quickselect(stack, 0, 2, 1);
	lst_quickselect(stack, 0, 2, 2);
}

void	little_sort(t_stack **stack, t_bounds b)
{
	if (b.r - b.p == 3)
		sort3(stack);
	else if (b.r - b.p == 2)
		sort2(stack);
}

t_group	*new_group(int gr_id, t_list *stack)
{
	t_group	*gr;

	gr = ft_memalloc(sizeof(t_group));
	if (gr)
	{
		gr->gr_id = gr_id;
		gr->stack = stack;
	}
	return (gr);
}

void	del_int(void *content, size_t content_size)
{
	++content_size;
	free(content);
}

void	full_split(t_stack **a, t_stack **b)
{
	t_group *cur;
	t_group	*tmp;
	int		gr_size;

	cur = (*a)->lst->content;
	gr_size = ft_lstlen(cur->stack);
	while (gr_size > 3)
	{
		split_median(cur);
		gr_size = ft_lstlen(cur->stack);
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*lst;
	t_group		*gr;

	lst = NULL;
	if (isvldarg(&argv[1], argc - 1))
		lst = read_args_stack(&argv[1], argc - 1);
	else
		ps_error("Error\n");
	gr = new_group(1, a->lst);
	a = new_stack(gr, 'a');
	b = new_stack(NULL, 'b');
	full_split(&a, &b);
	ft_lstiter(split_median(gr)->stack, print_int);
	ft_printf("-----\n");
	ft_lstiter(gr->stack, print_int);
	/*
	ft_printf("Stack a:\n");
	ft_lstiter(a->lst, print_int);
	ft_printf("\n");
	ft_printf("Stack b:\n");
	ft_lstiter(b->lst, print_int);
	*/
	return (0);
}
