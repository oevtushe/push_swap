/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:09:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 11:58:18 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "push_swap.h"

void	ps_error(char *message, int fd)
{
	ft_putstr_fd(message, 2);
	if (fd)
		close(fd);
	exit(1);
}
