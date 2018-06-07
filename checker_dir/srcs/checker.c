/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:26:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

/*
** Function puts numbers from argv into stack
*/

static t_list	*get_a(char **arr, int size)
{
	t_list *stack;

	stack = NULL;
	if (arr && *arr && isvldarg(&arr[0], size))
		stack = read_args_stack(&arr[0], size);
	else
		ps_error("Error\n");
	return (stack);
}

/*
** Function reads operations from fd
*/

static t_list	*get_ops(int fd)
{
	t_list *op_stack;

	op_stack = read_operations(fd);
	if (isvldops(op_stack))
	{
		ft_lstiter(op_stack, opc_lst_rebase);
		ft_lstcorder(&op_stack);
	}
	else
		ps_error("Error\n");
	return (op_stack);
}

static void		checker(char **arr, int size, t_odata *odata)
{
	t_stacks	*stacks;
	t_list		*op_stack;

	stacks = new_stacks(NULL, NULL);
	stacks->a = get_a(arr, size);
	op_stack = NULL;
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
	ft_lstdel(&op_stack, del_opc);
	free_stacks(&stacks);
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
	ft_memdel((void**)&odata);
	return (0);
}
