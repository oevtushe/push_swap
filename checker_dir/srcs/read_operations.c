/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:14:29 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 18:10:51 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pr(t_list *elem)
{
	ft_printf("%s\n", (char*)elem->content);
}

t_list	*read_operations(int fd)
{
	char	*line;
	t_list	*op_stack;
	t_list	*tmp;

	op_stack = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		//ft_printf("op = %s\n", line);
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(&op_stack, tmp);
		ft_strdel(&line);
	}
	ft_lstiter(op_stack, pr);
	return (op_stack);
}
