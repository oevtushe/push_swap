/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_opt_op_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:56:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 09:46:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_cmn(char *str)
{
	if (ft_strequ(str, "sa") || ft_strequ(str, "sb"))
		return (ft_strdup("ss"));
	else if (ft_strequ(str, "ra") || ft_strequ(str, "rb"))
		return (ft_strdup("rr"));
	else if (ft_strequ(str, "rra") || ft_strequ(str, "rrb"))
		return (ft_strdup("rrr"));
	return (NULL);
}

static void	init_tail(t_list **ops_a, t_list **ops_b, t_pair *start, t_list **common)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (start->first)
	{
		while (i < start->first)
		{
			tmp = ft_lstnew((*ops_a)->content, (*ops_a)->content_size);
			ft_lstadd(common, tmp);
			*ops_a = (*ops_a)->next;
			++i;
		}
	}
	else if (start->second)
	{
		while (i < start->second)
		{
			tmp = ft_lstnew((*ops_b)->content, (*ops_b)->content_size);
			ft_lstadd(common, tmp);
			*ops_b = (*ops_b)->next;
			++i;
		}
	}
}

static void	init_middle(t_list **lst, t_list **common, int cmn_len)
{
	t_list	*tmp;
	char	*cmop;

	while (cmn_len)
	{
		cmop = get_cmn((char*)(*lst)->content);
		tmp = ft_lstnew(cmop, ft_strlen(cmop) + 1);
		ft_lstadd(common, tmp);
		*lst = (*lst)->next;
		--cmn_len;
	}
}

static void	read_map(int **map, t_pair *map_size, t_pair *start, t_pair *finish)
{
	int		max;
	int		i;
	int		j;

	i = 0;
	max = 0;
	while (i < map_size->first)
	{
		j = 0;
		while (j < map_size->second)
		{
			if (map[i][j] > max)
			{
				finish->second = i;
				finish->first = j;
				max = map[i][j];
			}
			++j;
		}
		++i;
	}
	start->first = finish->first - (max - 1);
	start->second = finish->second - (max - 1);
}


t_list		*create_opt_op_lst(int **map, t_pair *map_size, t_list *ops_a, t_list *ops_b)
{
	t_pair	start;
	t_pair	finish;
	t_list	*common;
	t_list	*tmp;
	t_list	*lst3;

	common = NULL;
	read_map(map, map_size, &start, &finish);
	init_tail(&ops_a, &ops_b, &start, &common);
	if (finish.first + 1 != map_size->second)
		lst3 = ops_a;
	else 
		lst3 = ops_b;
	init_middle(&lst3, &common, finish.first - start.first + 1);
	while (lst3)
	{
		tmp = ft_lstnew(lst3->content, lst3->content_size);
		ft_lstadd(&common, tmp);
		lst3 = lst3->next;
	}
	ft_lstcorder(&common);
	return (common);
}
