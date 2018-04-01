/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:08:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/31 11:08:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			execute_swap(t_list *stack)
{
	int		st;
	void	*tmp;

	if (stack && stack->next)
	{
		st = 1;
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
	else
		st = 0;
	return (st);
}

t_excstat	execute_sswap(t_list *a, t_list *b)
{
	t_excstat	stat1;
	t_excstat	stat2;
	t_excstat	stat;

	stat1 = execute_swap(a) ? ES_AM : ES_NONE;
	stat2 = execute_swap(b) ? ES_BM : ES_NONE;
	if (stat1 == ES_AM && stat2 == ES_BM)
		stat = ES_BOTH;
	else if (stat1 == ES_AM)
		stat = stat1;
	else
		stat = stat2;
	return (stat);
}

int			execute_push(t_list **fst, t_list **scd)
{
	int		st;
	void	*tmp;

	if (scd && *scd)
	{
		st = 1;
		tmp = (*scd)->next;
		ft_lstadd(fst, *scd);
		*scd = tmp;
	}
	else
		st = 0;
	return (st);
}
