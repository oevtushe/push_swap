/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:25:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/01 18:29:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

void	checker_error(const char *message, int fd)
{
	ft_putstr_fd(message, 2);
	if (fd > 2)
		close(fd);
	exit(1);
}
