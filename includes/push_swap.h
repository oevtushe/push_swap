/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:21:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/03 09:17:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

typedef struct		s_stack
{
	char	name;
	t_list	*lst;
}					t_stack;

typedef struct		s_bounds
{
	int p;
	int r;
}					t_bounds;

int			isvldarg(char **args, int size);
t_list		*read_args_stack(char **data, int size);
void		ps_error(char *message);
int		    lstgeti(t_list *lst, int idx);
t_stack     *new_stack(t_list *lst, char name);
void	    lst_safe_swap(t_stack **stack, int i, int j);
int     	*lsttoari(t_list *lst);
int			lstgeti(t_list *lst, int idx);
int			lst_quickselect(t_stack **stack, int p, int r, int i);
int			arr_quickselect(int *arr, int p, int r, int i);
int			find_median(t_list *lst);
int			st_separate(t_stack **from, t_stack **to, t_bounds bounds, char which);
void		init_push(t_stack **stack, t_opc *op);
void		push_exec_pr(t_stack **st1, t_stack **st2, t_opc opc);

int			lmiddle_cmp(int v1, int v2);
int			hmiddle_cmp(int v1, int v2);

#endif
