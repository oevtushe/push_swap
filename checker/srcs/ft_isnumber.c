/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:10:34 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 15:08:59 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isnumber(char *str)
{
	int		rv;
	size_t	i;

	i = 0;
	rv = 0;
	if (str)
	{
		if (str[i] == '-' || str[i] == '+')
			++i;
		while (ft_isdigit(str[i]))
			++i;
		if (i && !str[i])
			rv = 1;
	}
	return (rv);
}
