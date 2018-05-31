/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:12:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 11:02:58 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "get_next_line.h"
# include "ft_printf.h"

typedef	enum	e_operation
{
	OP_NONE,
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

typedef	enum	e_excstat
{
	ES_NONE,
	ES_BM,
	ES_AM,
	ES_BOTH
}				t_excstat;

/*
** Operation container
*/

typedef	struct	s_opc
{
	t_operation	abbr;
	char		*op_name;
}				t_opc;

int			st_issorted(t_list_de *stack);
t_excstat	op_execute(t_list_de **a, t_list_de **b, t_operation op);
int			isvldarg(char **args, int size);
t_list_de	*read_args_stack(char **data, int size);
int			execute_swap(t_list_de *stack);
t_excstat	execute_sswap(t_list_de *a, t_list_de *b);
int			execute_push(t_list_de **fst, t_list_de **scd);
int			execute_rev_rotate(t_list_de **stack);
t_excstat	execute_rev_rrotate(t_list_de **a, t_list_de **b);
int			execute_rotate(t_list_de **stack);
t_excstat	execute_rrotate(t_list_de **a, t_list_de **b);
char		**split_arr(char **arr, int size, int *new_size);
void		free_str_arr(char ***arr, int size);
void		rebase_op_stack(t_list **op_stack);
t_opc		*new_opc(t_operation op, char *op_name);
t_opc		*get_opc(char *oper_nm);

#endif
