/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:00:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/08 10:10:43 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

# define PRINT_PROMPT ft_printf("\n%s%s->%s ", BOLD, GREEN, RESET)

typedef struct	s_bottom
{
	int		is_sp_printed;
	int		is_nm_printed;
	char	*separator;
	char	*name;
}				t_bottom;

typedef struct	s_uformat
{
	char		tl;
	char		tr;
	char		tm;
	char		bnl;
	char		bnr;
	char		btmm;
	char		btml;
	char		btmr;
}				t_uformat;

typedef	struct	s_pformat
{
	int			bi_ln;
	int			spcs;
	char		*color;
	t_excstat	stat;
	t_bottom	*ba;
	t_bottom	*bb;
	t_uformat	ufmt;
}				t_pformat;

typedef	struct	s_odata
{
	int			fd;
	int			debug;
	int			stat;
	t_uformat	ufmt;
	void		(*print) (t_stacks*, t_opc*, t_pformat*);
}				t_odata;

int				isvldops(t_list *op_stack);
void			print_info(t_stacks *stacks, t_opc *opc, t_pformat *pfmt);
void			print_row(t_stacks *stacks, t_pformat *fmt);
t_list			*read_operations(int fd);
int				st_issorted(t_list *stack);
void			op_executor(t_stacks *stacks, t_list *op_stack, t_odata *odata);
void			free_str_arr(char ***arr, int size);
char			*str_join_number(char *prefix, int num, char *suffix);
t_opc			*new_opc(t_operation op, char *op_name);
t_pformat		*new_pformat(t_list *a, t_uformat ufmt);
int				is_vldop(char *op);
void			op_read_and_exec(t_stacks *stacks,\
					t_list **op_stack, t_odata *odata);
void			init_format(t_pformat *pfmt, char *op_name, t_excstat stat);
char			*prompt(void);
void			print_extra(t_stacks *stacks, t_pformat *pfmt, char *text);
void			stat(t_list *lst);
void			verdict(t_stacks *stacks);
t_odata			*init_odata(char **args, int *si, int size);
void			pfmt_prep_to_next(t_pformat *pfmt);
void			free_pfmt(t_pformat **pfmt);
void			pretty_error(void);

#endif
