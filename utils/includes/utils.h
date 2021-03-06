/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:12:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 14:45:36 by oevtushe         ###   ########.fr       */
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

typedef struct	s_stacks
{
	t_list	*a;
	t_list	*b;
	int		grp_cnt;
}				t_stacks;

/*
** Operation container
*/

typedef	struct	s_opc
{
	t_operation	abbr;
	char		*op_name;
}				t_opc;

int				st_issorted(t_list *stack);
t_excstat		op_execute(t_stacks *stacks, t_operation op);
int				isvldarg(char **args, int size);
t_list			*read_args_stack(char **data, int size);
int				execute_swap(t_list *stack);
t_excstat		execute_sswap(t_stacks *stacks);
int				execute_push(t_list **fst, t_list **scd);
int				execute_rev_rotate(t_list **stack);
t_excstat		execute_rev_rrotate(t_stacks *stacks);
int				execute_rotate(t_list **stack);
t_excstat		execute_rrotate(t_stacks *stacks);
char			**split_arr(char **arr, int size, int *new_size);
void			free_str_arr(char ***arr, int size);
t_opc			*new_opc(t_operation op, char *op_name);
t_opc			*get_opc(char *oper_nm);
t_stacks		*new_stacks(t_list *a, t_list *b);
void			del_simple(void *content, size_t content_size);
void			del_opc(void *content, size_t content_size);
void			free_opc(t_opc **opc);
void			free_stacks(t_stacks **stacks);
void			ps_error(char *message);
void			opc_lst_rebase(t_list *elem);

#endif
