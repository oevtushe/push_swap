/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verdict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:41:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:13:59 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void verdict(t_list_de *a, t_list_de *b)
{
	if (!b && st_issorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
