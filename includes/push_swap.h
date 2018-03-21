/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:21:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/14 17:08:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_
# define PUSH_SWAP_

# include "ft_printf.h"
# include "get_next_line.h"

int			isvldarg(char **args, int size);
t_list		*read_args_stack(char **data, int size);
void		ps_error(char *message);

#endif
