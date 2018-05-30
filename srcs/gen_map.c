/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:07:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 10:22:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**create_map(t_list *ops_a, t_list *ops_b, t_pair *map_size)
{
	int i;
	int j;
	int	cols;
	int	rows;
	int **map;

	i = 0;
	cols = ft_lstlen(ops_a);
	rows = ft_lstlen(ops_b);
	map_size->first = rows;
	map_size->second = cols;
	map = (int**)malloc((rows + 1) * sizeof(int*));
	while (i < rows)
		map[i++] = (int*)malloc(cols * sizeof(int));
	map[i] = NULL;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
			map[i][j++] = 0;
		++i;
	}
	return (map);
}

int			**gen_map(t_list *ops_a, t_list *ops_b, t_pair *map_size)
{
	int		i;
	int		j;
	int		**map;
	t_list	*bg;

	i = 0;
	map = create_map(ops_a, ops_b, map_size);
	bg = ops_a;
	while (ops_b)
	{
		j = 0;
		ops_a = bg;
		while (ops_a)
		{
			if (ft_strequ((char *)ops_b->content, (char *)ops_a->content))
				map[i][j] = (i - 1 >= 0 && j - 1 >= 0) ?
					map[i - 1][j - 1] + 1 : 1;
			ops_a = ops_a->next;
			++j;
		}
		++i;
		ops_b = ops_b->next;
	}
	return (map);
}
