/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/03 09:50:28 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

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

static void		checker(char **arr, int size, t_odata *odata)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*op_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = get_a(arr, size);
	if (odata->debug)
		op_read_and_exec(&a_stack, &b_stack, odata->fd);
	else
	{
		op_stack = get_ops(odata->fd);
		op_executor(&a_stack, &b_stack, op_stack, odata->print);
	}
	if (odata->stat)
		stat(op_stack);
	verdict(a_stack, b_stack);
}

static t_odata	*init_odata(char **args, int *si)
{
	t_odata *odata;

	odata = ft_memalloc(sizeof(t_odata));
	odata->fd = 0;
	odata->debug = 0;
	odata->stat = 0;
	odata->print = NULL;
	if (ft_strequ(args[*si], "-c"))
	{
		odata->print = print_info;
		++(*si);
	}
	if (ft_strequ(args[*si], "-d"))
	{
		odata->print = print_info;
		odata->debug = 1;
		++(*si);
	}
	else if (ft_strequ(args[*si], "-fd"))
	{
		if ((odata->fd = open(args[++(*si)], O_RDONLY)) < 0)
			checker_error("Something wrong with the file !\n");
		++(*si);
	}
	else if (ft_strequ(args[*si], "-s"))
	{
		odata->stat = 1;
		++(*si);
	}
	return (odata);
}

int				main(int argc, char **argv)
{
	int		si;
	char	**arr;
	t_odata *odata;

	si = 1;
	if (argc < 2)
		return (1);
	odata = init_odata(argv, &si);
	arr = split_arr(&argv[si], argc - si, &si);
	checker(arr, si, odata);
	if (odata->fd > 0)
		close(odata->fd);
	free_str_arr(&arr, si);
	free(odata);
	return (0);
}
