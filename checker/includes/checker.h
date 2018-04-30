/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:00:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/30 15:07:52 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "utils.h"

typedef	struct	s_pformat
{
	int			bi_ln;
	int			spcs;
	char		*bottom;
	char		*color;
	t_excstat	stat;
}				t_pformat;

void			rebase_op_stack(t_list **op_stack);
int				isvldops(t_list *op_stack);
void			print_info(t_list *a, t_list *b, t_opc *opc, t_excstat stat);
void			print_row(t_list **a, t_list **b, t_pformat *fmt);
t_list			*read_operations(int fd);
void			checker_error(const char *message);
int				st_issorted(t_list *stack);
void			op_executor(t_list **a_stack, t_list **b_stack,
		t_list *op_stack, void print(t_list *, t_list *, t_opc *, t_excstat));
void			free_str_arr(char ***arr, int size);
char			*str_join_number(char *prefix, int num, char *suffix);

#endif
