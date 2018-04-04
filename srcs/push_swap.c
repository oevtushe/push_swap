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
	quickselect(stack, 0, 1, 1);
}

void	sort3(t_stack **stack)
{
	quickselect(stack, 0, 2, 1);
	quickselect(stack, 0, 2, 2);
}

void	little_sort(t_stack **stack, t_bounds b)
{
	if (b.r - b.p == 3)
		sort3(stack);
	else if (b.r - b.p == 2)
		sort2(stack);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*lst;
	t_bounds	ba;
	t_bounds	bb;

	lst = NULL;
	if (isvldarg(&argv[1], argc - 1))
		lst = read_args_stack(&argv[1], argc - 1);
	else
		ps_error("Error\n");
	ba.p = 0;
	ba.r = ft_lstlen(lst) - 1;
	bb.p = 0;
	bb.r = 0;
	a = new_stack(lst, 'a');
	b = new_stack(NULL, 'b');
	st_separate(&a, &b, ba, 'a');
	
	ft_printf("Stack a:\n");
	ft_lstiter(a->lst, print_int);
	ft_printf("\n");
	ft_printf("Stack b:\n");
	ft_lstiter(b->lst, print_int);
	return (0);
}
