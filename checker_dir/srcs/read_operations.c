/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:14:29 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/17 12:34:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list_de	*read_operations(int fd)
{
	char	*line;
	t_list_de	*op_stack;
	t_list_de	*tmp;

	op_stack = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_lstnew_de(line, ft_strlen(line) + 1);
		ft_lstadd_de(&op_stack, tmp);
		ft_strdel(&line);
	}
	return (op_stack);
}
