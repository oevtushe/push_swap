/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:07:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/05 16:08:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	del_simple(void *content, size_t content_size)
{
	++content_size;
	free(content);
}