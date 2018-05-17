/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_nmedians.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:56:54 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 11:54:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void		safe_del(t_list **begin, t_list *to_del)
{
	t_list *cur;
	t_list *next;
	t_list *prev;
	
	next = *begin;
	if (*begin == to_del)
	{
		next = (*begin)->next;
		free(*begin);
		*begin = next;
	}
	else
	{
		while (next != to_del)
		{
			prev = next;
			next = next->next;
		}
		prev->next = next->next;
		free(next);
	}
}
*/

static t_median	*new_median(int median, int elem_cnt)
{
	t_median *new;

	new = (t_median*)malloc(sizeof(t_median));
	new->median = median;
	new->push_cnt = elem_cnt;
	return (new);
}

static t_list	*f(t_list *elem)
{
	t_list *new;

	new = ft_lstnew(elem->content, sizeof(size_t));
	return (new);
}

static void		median_del(t_list **lst, int median)
{
	t_list *runner;
	t_list *prev;

	runner = *lst;
	while (*lst && *(int*)(*lst)->content < median)
	{
		runner = (*lst)->next;
		free(*lst);
		*lst = runner;
	}
	while (runner)
	{
		if (*(int*)runner->content < median)
		{
			prev->next = runner->next;
			free(runner);
			runner = prev->next;
		}
		else
		{
			prev = runner;
			runner = runner->next;
		}
	}
}

/*
static void		print2(t_list *elem)
{
	ft_printf("median = %d\n", ((t_median*)(elem->content))->median);
	ft_printf("push_cnt = %d\n\n", ((t_median*)(elem->content))->push_cnt);
}
*/

/*
static void		print(t_list *elem)
{
	ft_printf("elem = %d\n", *(int*)elem->content);
}
*/

t_list		*find_all_nmedians(t_list *lst, int size)
{
	t_list		*medians;
	int			elems_cnt;
	int			cur_med;
	t_list		*node;
	t_list		*cpy;

	medians = NULL;
	elems_cnt = size;
	cpy = ft_lstmap(lst, f);
	while (elems_cnt > 3)
	{
		cur_med = find_nmedian(cpy, elems_cnt);
		node = ft_lstnew(new_median(cur_med, elems_cnt / 2), sizeof(t_median));
		ft_lstadd(&medians, node);
		median_del(&cpy, cur_med);
		elems_cnt = elems_cnt & 1 ? (elems_cnt / 2) + 1 : (elems_cnt / 2);
	}
	ft_lstcorder(&medians);
	return (medians);
}
