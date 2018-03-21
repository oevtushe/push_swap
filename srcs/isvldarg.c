/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvldarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:34:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 16:25:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	vldval(unsigned int res, int sign, char *val, int i)
{
	if ((sign > 0 && res > INT_MAX) ||
			(sign < 0 && res > (-1L * INT_MIN)) ||
				(val[i]))
		return (0);
	return (1);
}

static int	isvldint(char *str)
{
	int				i;
	unsigned int	res;
	int				sign;
	int				len;

	i = 0;
	sign = 1;
	res = 0;
	len = -1;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] == '0')
		++i;
	while (++len < 10 && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return (vldval(res, sign, str, i));
}

int			isvldarg(char **args, int size)
{
	int	valid;
	int	cnt;

	valid = 0;
	cnt = size - 1;
	while (cnt >= 0 && ft_isnumber(args[cnt]) && isvldint(args[cnt]))
		--cnt;
	if (cnt < 0)
		valid = 1;
	valid = cnt < 0 && no_duplicates(args, size) ? 1 : 0;
	return (valid);
}
