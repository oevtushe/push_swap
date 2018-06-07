/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:23:41 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 11:47:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char		*str_join_number(char *prefix, int num, char *suffix)
{
	char	*tmp;
	char	*res;

	res = NULL;
	if (prefix && suffix)
	{
		tmp = ft_itoa(num);
		res = ft_strjoin(prefix, tmp);
		ft_strdel(&tmp);
		tmp = res;
		res = ft_strjoin(res, suffix);
		ft_strdel(&tmp);
	}
	return (res);
}
