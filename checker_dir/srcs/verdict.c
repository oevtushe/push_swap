/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verdict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 10:18:52 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void verdict(t_stacks *stacks)
{
	if (!stacks->b && st_issorted(stacks->a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
