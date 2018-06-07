/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:31:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "push_swap.h"

static void	cs_to_grp(t_list *elem)
{
	elem->content_size = 1;
}

static void	handle_args(char **args, int size, int *si, int *fd)
{
	if (ft_strequ(args[*si], "-fd") && size > 3)
	{
		*fd = open(args[*si + 1], O_TRUNC | O_CREAT | O_WRONLY, 0666);
		if (*fd < 0)
			ps_error("Something wrong with the file !\n");
		*si += 2;
	}
}

static void	finish(char ***arr, int size, t_stacks **stacks, int fd)
{
	if (fd > 2)
		close(fd);
	free_str_arr(arr, size);
	free_stacks(stacks);
}

void		sort_stacks(t_stacks *stacks, int fd)
{
	split_group_a(stacks, fd);
	while (stacks->b)
		split_group_b(stacks, fd);
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
	stacks = new_stacks(NULL, NULL);
	if (argc < 2)
		return (1);
	handle_args(argv, argc, &si, &fd);
	arr = split_arr(&argv[si], argc - si, &size);
	if (isvldarg(arr, size))
		stacks->a = read_args_stack(arr, size);
	else
		ps_error("Error\n");
	ft_lstiter(stacks->a, cs_to_grp);
	if (!st_issorted(stacks->a))
		sort_stacks(stacks, fd);
	finish(&arr, size, &stacks, fd);
	return (0);
}
