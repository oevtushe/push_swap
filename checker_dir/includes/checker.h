/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:00:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/31 11:07:50 by oevtushe         ###   ########.fr       */
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
	void	(*print) (t_list_de*, t_list_de*, t_opc*, t_pformat*);
}				t_odata;

int				isvldops(t_list_de *op_stack);
void			print_info(t_list_de *a, t_list_de *b, t_opc *opc, t_pformat*);
void			print_row(t_list_de **a, t_list_de **b, t_pformat *fmt);
t_list_de		*read_operations(int fd);
void			checker_error(const char *message);
void			op_executor(t_list_de **a_stack, t_list_de **b_stack,
		t_list_de *op_stack, void print(t_list_de *, t_list_de *, t_opc *, t_pformat*));
void			free_str_arr(char ***arr, int size);
char			*str_join_number(char *prefix, int num, char *suffix);
t_opc			*new_opc(t_operation op, char *op_name);
t_pformat		*new_pformat(t_list_de *a);
int				is_vldop(char *op);
void			op_read_and_exec(t_list_de **a, t_list_de **b, t_list_de **op_stack, int fd);
void			init_format(t_pformat *pfmt, char *op_name, t_excstat stat);
char			*prompt(void);
void			print_extra(t_list_de *a_stack, t_list_de *b_stack, t_pformat *pfmt, char *text);
void			stat(t_list_de *lst);
void 			verdict(t_list_de *a, t_list_de *b);
t_odata			*init_odata(char **args, int *si, int size);

#endif
