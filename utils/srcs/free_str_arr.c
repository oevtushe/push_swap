/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:07:21 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/06 12:05:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			free_str_arr(char ***arr, int size)
{
	int		i;

	i = 0;
	if (arr && *arr)
	{
		while (i < size)
			ft_memdel((void**)&(*arr)[i++]);
		ft_memdel((void**)arr);
	}
}

