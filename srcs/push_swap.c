/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 11:29:58 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "push_swap.h"

static void	handle_args(char **args, int size, int *si, int *fd)
{
	if (ft_strequ(args[*si], "-fd") && size > 3)
	{
		*fd = open(args[*si + 1], O_TRUNC|O_CREAT|O_WRONLY, 0666);
		if (*fd < 0)
			ps_error("Something wrong with the file !\n");
		*si += 2;
	}
}

void		sort_stacks(t_stacks *stacks, int fd)
{
	int		group_cnt;

	group_cnt = 0;
	split_group_a(stacks, &group_cnt, fd);
	while (stacks->b)
		split_group_b(stacks, &group_cnt, fd);
}

int			main(int argc, char **argv)
{
	t_list		*a;
	t_stacks	*stacks;
	char		**arr;
	int			size;
	int			fd;
	int			si;

	si = 1;
	fd = 1;
	a = NULL;
	if (argc < 2)
		return (1);
	handle_args(argv, argc, &si, &fd);
	arr = split_arr(&argv[si], argc - si, &size);
	if (isvldarg(arr, size))
		a = read_args_stack(arr, size);
	else
		ps_error("Error\n");
	rebase_lst_data(a);
	stacks = new_stacks(a, NULL);
	if (!st_issorted(a))
		sort_stacks(stacks, fd);
	free_str_arr(&arr, size);
	free_stacks(&stacks);
	if (fd > 2)
		close(fd);
	return (0);
}
