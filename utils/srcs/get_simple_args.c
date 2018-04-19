/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simple_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:03:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/19 10:21:54 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		sub_arr_len(char **arr)
{
	int i;

	i = 0;
	if (arr)
		while (arr[i])
			++i;
	return (i);
}

static void		resize_arr(char ***arr, int old_size, int new_size)
{
	int		i;
	char	**buff;

	i = -1;
	if (new_size > old_size)
	{
		buff = (char **)ft_memalloc(sizeof(char *) * new_size);
		if (buff)
		{
			while (++i < old_size)
				buff[i] = (*arr)[i];
			free(*arr);
			*arr = buff;
		}
	}
}

/*
** Splits string and appends elements to arr.
*/

static int		split_and_put(char ***arr, char *to_split, int *j, int size)
{
	int		i;
	int		new_size;
	char	**sa;

	i = 0;
	sa = ft_strsplit(to_split, ' ');
	new_size = size + sub_arr_len(sa) - 1;
	resize_arr(arr, size, new_size);
	while (sa[i])
		(*arr)[++(*j)] = sa[i++];
	free(sa);
	return (new_size);
}

/*
** Recreates string array with splitted strings in.
*/

char			**split_arr(char **arr, int size, int *new_size)
{
	int		i;
	int		j;
	char	**new_arr;

	i = -1;
	j = -1;
	*new_size = size;
	new_arr = (char **)ft_memalloc(sizeof(char *) * *new_size);
	while (++i < size)
	{
		if (ft_strchr(arr[i], ' '))
			*new_size = split_and_put(&new_arr, arr[i], &j, *new_size);
		else
			new_arr[++j] = ft_strdup(arr[i]);
	}
	return (new_arr);
}
