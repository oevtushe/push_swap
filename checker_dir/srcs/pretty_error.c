/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:09:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/08 10:14:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pretty_error(void)
{
	ps_error("Wrong pretty format !\n\nThe true format is \
--pretty=\'12345678' where:\n\
1 -> top left,\n\
2 -> top middle,\n\
3 -> top right,\n\
4 -> boundary left,\n\
5 -> boundary right,\n\
6 -> bottom left,\n\
7 -> bottom middle,\n\
8 -> bottom right\n");
}
