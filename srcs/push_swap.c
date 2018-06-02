/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 18:32:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "push_swap.h"

static void	sort_stacks(t_stacks *stacks, int fd)
{
	int		group_cnt;

	group_cnt = 0;
	split_group_a(stacks, &group_cnt, fd);
	while (stacks->b)
		split_group_b(stacks, &group_cnt, fd);
}

static void	handle_options(char **argv, int size, int *si, int *fd)
{
	if (size > 3 && ft_strequ(argv[*si], "-fd"))
	{
		*fd = open(argv[*si + 1], O_WRONLY|O_CREAT, 0666);
		if (*fd < 0)
			ps_error("Something wrong with the file\n", 0);
		*si += 2;
	}
}

int			main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**arr;
	int			size;
	int			fd;
	int			si;

	si = 1;
	fd = 1;
	size = 0;
	if (argc < 2)
		return (1);
	stacks = new_stacks(NULL, NULL);
	handle_options(argv, argc, &si, &fd);
	arr = split_arr(&argv[si], argc - si, &size);
	if (isvldarg(arr, size))
		stacks->a = read_args_stack(arr, size);
	else
		ps_error("Error\n", fd);
	rebase_lst_data(stacks->a);
	if (!st_issorted(stacks->a))
		sort_stacks(stacks, fd);
	free_str_arr(&arr, size);
	free_stacks(&stacks);
	if (fd > 2)
		close(fd);
	return (0);
}
