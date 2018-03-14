/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:00:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/13 16:08:27 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"

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

void	rebase_op_stack(t_list **op_stack);

int		isvldarg(char **args, int size);
int		isvldops(t_list *op_stack);

/*
** Operation executors
*/

void	op_executor(t_list **a_stack, t_list *op_stack);
void	execute_rev_rotate(t_list **stack);
void	execute_rev_rrotate(t_list **a, t_list **b);
void	execute_rotate(t_list **stack);
void	execute_rrotate(t_list **a, t_list **b);
void	execute_swap(t_list *stack);
void	execute_sswap(t_list *a, t_list *b);
void	execute_push(t_list **fst, t_list **scd);

int		ft_isnumber(char *str);
t_list	*read_args_stack(char **data, int size);
t_list	*read_operations(int fd);
void	checker_error(const char *message);

int		st_issorted(t_list *stack);

#endif
