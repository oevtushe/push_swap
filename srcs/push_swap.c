/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:30:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/29 17:38:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lstget(t_list *list, int idx)
{
	int		i;

	i = 0;
	while (list && i < idx)
	{
		++i;
		list = list->next;
	}
	return (*(int*)list->content);
}

void	print_swap_td(int btw, char st_name)
{
	int i;

	i = btw;
	if (i > 0)
	{
		while (i--)
		{
			ft_printf("s%c\n", st_name);
			ft_printf("r%c\n", st_name);
		}
	}
}

void	print_swap_dt(int btw, char st_name)
{
	int i;

	i = btw;
	if (i > 0)
	{
		while (i--)
		{
			ft_printf("rr%c\n", st_name);
			ft_printf("s%c\n", st_name);
		}
	}
}

typedef	struct		s_stack
{
	char st_name;
	t_list *list;
}					t_stack;

t_stack	*new_stack(char st_name, t_list *list)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack)
	{
		stack->st_name = st_name;
		stack->list = list;
	}
	return (stack);
}

void	print_swap(int i, int j, int r, char st_name)
{
	int coa;
	int cob;

	if (i != j)
	{
		coa = ((j - i + 1) - 2) * 4 + 1;
		cob = (r - (j - i)) * 4 + 3;
		//ft_printf("----- coa = %d, cob = %d, r = %d -----\n", coa, cob, r);
		if (coa > cob)
		{
			print_swap_dt(r - (j - i) - 1, st_name);
			ft_printf("rr%c\n", st_name);
			ft_printf("s%c\n", st_name);
			ft_printf("r%c\n", st_name);
			print_swap_td(r - (j - i) - 1, st_name);
		}
		else
		{
			print_swap_td((j - i) - 1, st_name);
			ft_printf("s%c\n", st_name);
			print_swap_dt((j  - i) - 1, st_name);
		}
	}
}

void	swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	print_int(t_list *item)
{
	ft_printf("%d\n", *(int*)item->content);
}

void	push_back(int size, char st_name)
{
	while (size--)
		ft_printf("p%c\n", st_name);
}

void	print_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_printf("%d ", arr[i++]);
	ft_putchar('\n');
}

int		partition(int *arr, int b, int e, char st_name)
{
	int		i;
	int		j;
	char	st_ops;
	int		pivot;

	i = b - 1;
	j = e + 1;
	pivot = arr[b];
	st_ops = (st_name == 'a') ? 'b' : 'a';
	while (1)
	{
		while (arr[++i] < pivot)
			ft_printf("p%c\n", st_ops);
		while (arr[--j] > pivot);
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
			print_swap(i, j, e, st_name);
			ft_printf("p%c\n", st_ops);
		}
		else
			return (j);
	}
}

void	rev_ia(int *arr, int size)
{
	int i;
	int j;
	int	c;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		c = arr[i];
		arr[i] = arr[j];
		arr[j] = c;
		++i;
		--j;
	}
}

void	quicksort(int *arr, int b, int r, char st_name)
{
	int		p;
	char	st_ops;

	st_ops = (st_name == 'a') ? 'b' : 'a';
	if (b < r)
	{
		p = partition(arr, b, r, st_name);
		rev_ia(arr, p + 1);
		print_arr(arr, 4);

		quicksort(arr, b, p, st_ops);
		quicksort(arr, p + 1, r, st_name);

		push_back(p ? p + 1 : p, st_name);
	}
}

int		*ft_getia(char **arr, const int size)
{
	int i;
	int	*ia;

	i = 0;
	ia = ft_memalloc(sizeof(int) * size);
	while (i < size)
	{
		ia[i] = ft_atoi(arr[i]);
		++i;
	}
	return (ia);
}

int		main(int argc, char **argv)
{
	int		i;
	int		*arr;

	arr = NULL;
	if (isvldarg(&argv[1], argc - 1))
		arr = ft_getia(&argv[1], argc - 1);
	else
		ps_error("Error\n");
	quicksort(arr, 0, argc - 2, 'a');
	i = 0;
	return (0);
}
