/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:18:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:45:32 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lmiddle_cmp(int v1, int v2)
{
	if (v1 < v2)
		return (1);
	return (0);
}

int		hmiddle_cmp(int v1, int v2)
{
	if (v1 > v2)
		return (1);
	return (0);
}
