/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verdict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/02 10:42:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void verdict(t_list *a, t_list *b)
{
	if (!b && st_issorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}