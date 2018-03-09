/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 15:54:10 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdio.h>

void	print_str_elem(t_list *elem)
{
	ft_putstr((char *)elem->content);
	ft_putchar('\n');
}

int		st_issorted(t_list *stack)
{
	int cur;
	int	prev;
	int	srt;

	srt = 0;
	if (stack)
	{
		prev = *(int *)stack->content;
		while (stack)
		{
			cur = *(int *)stack->content;
			if (cur < prev)
				break ;
			++srt;
			stack = stack->next;
			prev = cur;
		}
		srt = srt > 0 && !stack ? 1 : 0;
	}
	return (srt);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*op_stack;

	if (argc < 2)
		return (1);
	lst = NULL;
	if (isvldarg(&argv[1], argc - 1))
		lst = read_args_stack(&argv[1], argc - 1);
	else
		checker_error("Error\n");
	op_stack = read_operations(1);
	if (isvldops(op_stack))
		rebase_op_stack(&op_stack);
	else
		checker_error("Error\n");
	op_executor(&lst, op_stack);
	if (st_issorted(lst))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
