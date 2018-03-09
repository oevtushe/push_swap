/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:00:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/09 14:08:26 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

typedef	enum	e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}				t_operation;

/*
** Operation container
*/

typedef	struct	s_opc
{
	t_operation	abbr;
	char		*op_name;
}				t_opc;

int		isvldarg(char **args, int size);
int		isvldops(t_list *op_stack);
void	rebase_op_stack(t_list **op_stack);

int		ft_isnumber(char *str);
t_list	*read_args_stack(char **data, int size);
t_list	*read_operations(int fd);
void	checker_error(const char *message);

#endif
