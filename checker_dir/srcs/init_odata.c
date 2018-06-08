/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_odata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:17:51 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/08 10:22:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

static int	is_key(char *str)
{
	if (ft_strequ(str, "-c") || ft_strequ(str, "-d") ||
			ft_strequ(str, "-s") || ft_strequ(str, "-fd") ||
				ft_strnstr(str, "--pretty=", 9))
		return (1);
	return (0);
}

static void	init_pretty(char *fstr, t_odata *odata)
{
	odata->ufmt.tl = fstr[0];
	odata->ufmt.tm = fstr[1];
	odata->ufmt.tr = fstr[2];
	odata->ufmt.bnl = fstr[3];
	odata->ufmt.bnr = fstr[4];
	odata->ufmt.btml = fstr[5];
	odata->ufmt.btmm = fstr[6];
	odata->ufmt.btmr = fstr[7];
}

static void	def_pretty(t_odata *odata)
{
	odata->ufmt.tl = ' ';
	odata->ufmt.tr = ' ';
	odata->ufmt.tm = '_';
	odata->ufmt.bnl = '|';
	odata->ufmt.bnr = '|';
	odata->ufmt.btmm = '_';
	odata->ufmt.btml = '|';
	odata->ufmt.btmr = '|';
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
	if (ft_strnstr(key, "--pretty=", 9))
	{
		if (ft_strlen(key) == 17)
		{
			odata->print = print_info;
			init_pretty(&key[9], odata);
		}
		else
			pretty_error();
	}
}

/*
** Function initializes structure holdings option-based data
*/

t_odata		*init_odata(char **args, int *si, int size)
{
	t_odata *odata;

	odata = (t_odata *)ft_memalloc(sizeof(t_odata));
	def_pretty(odata);
	while (*si < size && is_key(args[*si]))
	{
		opt_identify(args[*si], odata);
		if (ft_strequ(args[*si], "-fd"))
			if ((odata->fd = open(args[++(*si)], O_RDONLY)) < 0)
				ps_error("Something wrong with the file !\n");
		++(*si);
	}
	return (odata);
}
