/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/02 10:21:22 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

static t_list	*get_a(char **arr, int size, int fd)
{
	t_list *stack;

	stack = NULL;
	if (arr && *arr && isvldarg(&arr[0], size))
		stack = read_args_stack(&arr[0], size);
	else
		checker_error("Error\n", fd);
	return (stack);
}

static t_list	*get_ops(int fd)
{
	t_list *op_stack;

	op_stack = read_operations(fd);
	if (isvldops(op_stack))
	{
		ft_lstiter(op_stack, nm_to_opc);
		ft_lstcorder(&op_stack);
	}
	else
		checker_error("Error\n", fd);
	return (op_stack);
}

static void		del_stack(void *content, size_t content_size)
{
	++content_size;
	free(content);
}

static void		checker(char **arr, int size, t_odata *odata)
{
	t_list		*a_stack;
	t_stacks 	*stacks;
	t_list		*op_stack;

	a_stack = NULL;
	op_stack = NULL;
	a_stack = get_a(arr, size, odata->fd);
	stacks = new_stacks(a_stack, NULL);
	if (odata->debug)
	{
		op_read_and_exec(stacks, &op_stack, odata->fd);
		ft_lstcorder(&op_stack);
	}
	else
	{
		op_stack = get_ops(odata->fd);
		op_executor(stacks, op_stack, odata->print);
	}
	if (odata->stat)
		stat(op_stack);
	verdict(stacks);
	ft_lstdel(&stacks->a, del_stack);
	ft_lstdel(&stacks->b, del_stack);
	ft_lstdel(&op_stack, del_opc);
	free(stacks);
}

int				main(int argc, char **argv)
{
	int		si;
	char	**arr;
	t_odata *odata;

	si = 1;
	if (argc < 2)
		return (1);
	odata = init_odata(argv, &si, argc);
	arr = split_arr(&argv[si], argc - si, &si);
	checker(arr, si, odata);
	if (odata->fd > 2)
		close(odata->fd);
	free_str_arr(&arr, si);
	free(odata);
	system("leaks checker");
	return (0);
}
