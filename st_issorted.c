/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:54:51 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 15:54:58 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		st_issorted(t_list *stack)
{
	int cur;
	int	prev;
	int	srt;

	srt = 0;
	if (stack)
	{
		prev = *(int *)stack->content;
		while (stack)
		{
			cur = *(int *)stack->content;
			if (cur < prev)
				break ;
			++srt;
			stack = stack->next;
			prev = cur;
		}
		srt = srt > 0 && !stack ? 1 : 0;
	}
	return (srt);
}
