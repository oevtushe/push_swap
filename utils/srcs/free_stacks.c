/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:46:48 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/05 17:47:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_stacks(t_stacks **stacks)
{
	ft_lstdel(&(*stacks)->a, del_simple);
	ft_lstdel(&(*stacks)->b, del_simple);
	free(*stacks);
	*stacks = NULL;
}
