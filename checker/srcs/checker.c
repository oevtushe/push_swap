/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/21 12:57:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "ft_printf.h"

static void		verdict(t_list *a, t_list *b)
{
	if (!b && st_issorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

static t_list	*get_a(char **arr, int size)
{
	t_list *stack;

	stack = NULL;
	if (isvldarg(&arr[0], size))
		stack = read_args_stack(&arr[0], size);
	else
		checker_error("Error\n");
	return (stack);
}

static t_list	*get_ops(void)
{
	t_list *op_stack;

	op_stack = read_operations(1);
	if (isvldops(op_stack))
		rebase_op_stack(&op_stack);
	else
		checker_error("Error\n");
	return (op_stack);
}

int				main(int argc, char **argv)
{
	int		si;
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*op_stack;
	void	(*print) (t_list *, t_list *, t_opc *, t_excstat);

	si = 1;
	a_stack = NULL;
	b_stack = NULL;
	print = NULL;
	if (argc < 2)
		return (1);
	if (ft_strequ(argv[si], "-c"))
	{
		print = print_info;
		++si;
	}
	a_stack = get_a(&argv[si], argc - si);
	op_stack = get_ops();
	op_executor(&a_stack, &b_stack, op_stack, print);
	verdict(a_stack, b_stack);
	return (0);
}
