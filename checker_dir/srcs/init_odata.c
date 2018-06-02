/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_odata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:17:51 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 18:28:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

static int	is_key(char *str)
{
	if (ft_strequ(str, "-c") || ft_strequ(str, "-d") ||
			ft_strequ(str, "-s") || ft_strequ(str, "-fd"))
		return (1);
	return (0);
}

static void	opt_identify(char *key, t_odata *odata)
{
	if (ft_strequ(key, "-c"))
		odata->print = print_info;
	if (ft_strequ(key, "-d"))
	{
		odata->print = print_info;
		odata->debug = 1;
	}
	if (ft_strequ(key, "-s"))
		odata->stat = 1;
}

t_odata		*init_odata(char **args, int *si, int size)
{
	t_odata *odata;

	odata = (t_odata *)ft_memalloc(sizeof(t_odata));
	while (*si < size && is_key(args[*si]))
	{
		opt_identify(args[*si], odata);
		if (ft_strequ(args[*si], "-fd"))
			if ((odata->fd = open(args[++(*si)], O_RDONLY)) < 0)
				checker_error("Something wrong with the file !\n", 0);
		++(*si);
	}
	return (odata);
}
