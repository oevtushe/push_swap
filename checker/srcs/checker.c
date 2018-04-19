/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/19 10:12:27 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

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

static t_list	*get_ops(int fd)
{
	t_list *op_stack;

	op_stack = read_operations(fd);
	if (isvldops(op_stack))
		rebase_op_stack(&op_stack);
	else
		checker_error("Error\n");
	return (op_stack);
}

void			checker(char **arr, int size, \
		void (*print) (t_list*, t_list*, t_opc*, t_excstat), int fd)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*op_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = get_a(arr, size);
	op_stack = get_ops(fd);
	op_executor(&a_stack, &b_stack, op_stack, print);
	verdict(a_stack, b_stack);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		si;
	void	(*print) (t_list*, t_list*, t_opc*, t_excstat);
	char	**arr;

	fd = 0;
	si = 1;
	print = NULL;
	if (argc < 2)
		return (1);
	if (ft_strequ(argv[si], "-c"))
	{
		print = print_info;
		++si;
	}
	if (ft_strequ(argv[si], "-fd"))
	{
		if ((fd = open(argv[++si], O_RDONLY)) < 0)
			checker_error("Something wrong with the file !\n");
		++si;
	}
	arr = split_arr(&argv[si], argc - si, &si);
	checker(arr, si, print, fd);
	if (fd > 0)
		close(fd);
	free_str_arr(&arr, si);
	return (0);
}
