/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:00:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/05 18:15:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "utils.h"

# define PRINT_PROMPT ft_printf("\n%s%s->%s ", BOLD, GREEN, RESET)

typedef struct	s_bottom
{
	int		is_sp_printed;
	int		is_nm_printed;
	char	*separator;
	char	*name;
}				t_bottom;

typedef	struct	s_pformat
{
	int			bi_ln;
	int			spcs;
	char		*color;
	t_excstat	stat;
	t_bottom	*ba;
	t_bottom	*bb;
}				t_pformat;

typedef	struct	s_odata
{
	int		fd;
	int		debug;
	int		stat;
	void	(*print) (t_stacks*, t_opc*, t_pformat*);
}				t_odata;

int				isvldops(t_list *op_stack);
void			print_info(t_stacks *stacks, t_opc *opc, t_pformat*);
void			print_row(t_stacks *stacks, t_pformat *fmt);
t_list			*read_operations(int fd);
void			checker_error(const char *message);
int				st_issorted(t_list *stack);
void			op_executor(t_stacks *stacks, t_list *op_stack,
		void print(t_stacks*, t_opc *, t_pformat*));
void			free_str_arr(char ***arr, int size);
char			*str_join_number(char *prefix, int num, char *suffix);
t_opc			*new_opc(t_operation op, char *op_name);
t_pformat		*new_pformat(t_list *a);
int				is_vldop(char *op);
void			op_read_and_exec(t_stacks *stacks, int fd);
void			init_format(t_pformat *pfmt, char *op_name, t_excstat stat);
char			*prompt(void);
void			print_extra(t_stacks *stacks, t_pformat *pfmt, char *text);
void			stat(t_list *lst);
void 			verdict(t_stacks *stacks);
t_odata			*init_odata(char **args, int *si, int size);

#endif
