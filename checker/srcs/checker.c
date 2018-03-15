/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/15 11:42:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_str_elem(t_list *elem)
{
	ft_putstr((char *)elem->content);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*op_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc < 2)
		return (1);
	if (isvldarg(&argv[1], argc - 1))
		a_stack = read_args_stack(&argv[1], argc - 1);
	else
		checker_error("Error\n");
	op_stack = read_operations(1);
	if (isvldops(op_stack))
		rebase_op_stack(&op_stack);
	else
		checker_error("Error\n");
	op_executor(&a_stack, &b_stack, op_stack);
	if (!b_stack && st_issorted(a_stack))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
