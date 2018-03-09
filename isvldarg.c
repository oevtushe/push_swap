/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvldarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:34:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 09:34:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	no_duplicates(char **args, int size)
{
	int	val;
	int	i;
	int	j;
	int	rs;

	i = size;
	rs = 1;
	while (i--)
	{
		val = ft_atoi(args[i]);
		j = i;
		while (--j >= 0)
		{
			if (val == ft_atoi(args[j]))
			{
				rs = 0;
				break ;
			}
		}
	}
	return (rs);
}

int			isvldarg(char **args, int size)
{
	int	valid;
	int	cnt;

	valid = 0;
	cnt = size - 1;
	while (cnt >= 0 && ft_isnumber(args[cnt]))
		--cnt;
	if (cnt < 0)
		valid = 1;
	valid = cnt < 0 && no_duplicates(args, size) ? 1 : 0;
	return (valid);
}
